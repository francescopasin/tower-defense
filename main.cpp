#include <QApplication>
#include <memory>

#include "model/exception.h"
#include "view/mainwindow.h"

using std::make_shared;
using std::vector;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // Model
    // ========================================================================
    auto model = make_shared<model::GameModel>();

    view::MainWindow window(model);

    // Start application
    window.show();
    return a.exec();
}
