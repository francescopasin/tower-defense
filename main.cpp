#include <QApplication>

#include "app/shortcuts.h"
#include "model/exception.h"
#include "view/mainwindow.h"

using std::vector;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // Model
    // ========================================================================
    auto model = model::make_shared<model::GameModel>();

    view::MainWindow window(model);

    // Start application
    window.show();
    return a.exec();
}
