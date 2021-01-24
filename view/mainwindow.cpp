#include "view/mainwindow.h"

#include <QFontDatabase>
#include <QResizeEvent>
#include <QSettings>

namespace view {

MainWindow::MainWindow(const vector<QWidget *> &screens) : stack(new QStackedWidget()) {
    setWindowTitle("Tower Defense");

    setMinimumSize(QSize(1280, 720));
    resize(QSize(1280, 720));

    // Restore user settings
    readSettings();

    // Add fonts
    QFontDatabase::addApplicationFont(":/assets/fonts/PressStart2P-Regular.ttf");

    // Insert screens in stack

    for (auto screen : screens) {
        stack->addWidget(screen);
    }

    setCentralWidget(stack);
}

void MainWindow::readSettings() {
    // Restore last window state (position, size)
    QSettings settings("TeamPlemento", "TowerDefense");
    restoreGeometry(settings.value("geometry").toByteArray());
    restoreState(settings.value("windowState").toByteArray());
}

void MainWindow::closeEvent(QCloseEvent *event) {
    // Save window state (position, size)
    QSettings settings("TeamPlemento", "TowerDefense");
    settings.setValue("geometry", saveGeometry());
    settings.setValue("windowState", saveState());
    QMainWindow::closeEvent(event);
}

void MainWindow::setScreen(app::Routes route) {
    switch (route) {
        default:
        case app::Routes::InitialScreen:
            stack->setCurrentIndex(0);
            break;
        case app::Routes::GameScreen:
            stack->setCurrentIndex(1);
            break;
    }
}

}  // namespace view
