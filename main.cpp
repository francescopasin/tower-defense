#include <QApplication>
#include <memory>
#include <vector>

#include "app/routes.h"
#include "controller/gamecontroller.h"
#include "controller/navigationcontroller.h"
#include "view/mainwindow.h"
#include "view/screens/gameScreen/gamescene.h"
#include "view/screens/gameScreen/gameview.h"
#include "view/screens/initialScreen/initialscreenscene.h"
#include "view/screens/initialScreen/initialscreenview.h"

using std::make_shared;
using std::vector;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // Model
    // ========================================================================
    auto model = make_shared<model::GameModel>();

    // Views
    // ========================================================================
    auto initialScreenScene = make_shared<view::InitialScreenScene>();
    auto initialScreenView = new view::InitialScreenView(initialScreenScene);

    auto gameScene = make_shared<view::GameScene>(model);
    auto gameView = new view::GameView(gameScene);

    vector<QWidget *> screens{initialScreenView, gameView};

    auto window = make_shared<view::MainWindow>(screens);

    // Controllers
    // ========================================================================
    auto navigationController = new controller::NavigationController(window);
    auto gameController = new controller::GameController(model, gameScene);

    // Views - Controllers association
    // ========================================================================
    QObject::connect(
        gameScene.get(),
        &view::GameScene::playPauseButtonPressed,
        gameController,
        &controller::GameController::playPause);

    QObject::connect(
        gameScene.get(),
        &view::GameScene::fastForwardButtonPressed,
        gameController,
        &controller::GameController::fastForward);

    QObject::connect(
        gameScene.get(),
        &view::GameScene::addTurretSignal,
        gameController,
        &controller::GameController::addTurret);

    QObject::connect(
        initialScreenScene.get(),
        &view::InitialScreenScene::startButtonPressed,
        navigationController,
        [=]() { navigationController->navigateTo(app::Routes::GameScreen); });

    // TODO: connect start button to game controller start

    // Start application
    window->show();
    return a.exec();
}
