#include <QApplication>
#include <memory>
#include <vector>

#include "app/routes.h"
#include "controller/gamecontroller.h"
#include "controller/navigationcontroller.h"
#include "controller/setmapcontroller.h"
#include "view/mainwindow.h"
#include "view/screens/gameScreen/gamescene.h"
#include "view/screens/gameScreen/gameview.h"
#include "view/screens/initialScreen/initialscreenscene.h"
#include "view/screens/initialScreen/initialscreenview.h"
#include "view/screens/setMapScreen/setmapscene.h"
#include "view/screens/setMapScreen/setmapview.h"

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

    auto setMapScene = make_shared<view::SetMapScene>();
    auto setMapView = new view::SetMapView(setMapScene);

    vector<QWidget *> screens{initialScreenView, gameView, setMapView};

    auto window = make_shared<view::MainWindow>(screens);

    // Controllers
    // ========================================================================
    auto navigationController = new controller::NavigationController(window);
    auto gameController = new controller::GameController(model, gameScene);
    auto setMapController = new controller::SetMapController(model, setMapScene, gameScene);

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

    QObject::connect(
        initialScreenScene.get(),
        &view::InitialScreenScene::setMapButtonPressed,
        navigationController,
        [=]() { navigationController->navigateTo(app::Routes::SetMapScreen); });

    QObject::connect(
        setMapScene.get(),
        &view::SetMapScene::saveButtonPressed,
        setMapController,
        &controller::SetMapController::saveToFile);

    QObject::connect(
        initialScreenScene.get(),
        &view::InitialScreenScene::uploadMapButtonPressed,
        setMapController,
        &controller::SetMapController::uploadFromFile);

    QObject::connect(
        setMapScene.get(),
        &view::SetMapScene::backButtonPressed,
        navigationController,
        [=]() { navigationController->back(); });

    // TODO: connect start button to game controller start

    // Start application
    window->show();
    return a.exec();
}
