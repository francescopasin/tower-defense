#include <QApplication>
#include <memory>

#include "controller/gamecontroller.h"
#include "view/mainwindow.h"

using std::make_shared;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    auto model = make_shared<model::GameModel>();
    auto gameScene = make_shared<view::GameScene>(model);

    auto controller = controller::GameController(model, gameScene);

    view::GameView gameView(gameScene);

    auto window = view::MainWindow(&gameView);
    window.show();

    return a.exec();
}
