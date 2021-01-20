#include <QApplication>
#include <memory>

#include "controller/gamecontroller.h"
#include "view/mainwindow.h"

using std::make_shared;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    auto model = make_shared<model::GameModel>();
    auto gameView = make_shared<view::GameView>(model);

    auto controller = controller::GameController(model, gameView);

    auto window = view::MainWindow(gameView);
    window.show();

    return a.exec();
}
