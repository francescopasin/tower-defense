#include "mainwindow.h"

#include <QDebug>
#include <QFontDatabase>
#include <QGraphicsRectItem>
#include <QMenuBar>
#include <QResizeEvent>
#include <QSettings>
#include <QVBoxLayout>

namespace view {

MainWindow::MainWindow(const SP<model::GameModel>& model, const SP<GameView>& gameView) {
    setWindowTitle("Tower Defense");

    setMinimumSize(QSize(1280, 720));
    resize(QSize(1280, 720));

    // Restore user settings
    readSettings();

    // Add fonts
    QFontDatabase::addApplicationFont(":/assets/fonts/PressStart2P-Regular.ttf");

    setCentralWidget(gameView.get());
}

void MainWindow::readSettings() {
    // Restore last window state (position, size)
    QSettings settings("TeamPlemento", "TowerDefense");
    restoreGeometry(settings.value("geometry").toByteArray());
    restoreState(settings.value("windowState").toByteArray());
}

void MainWindow::closeEvent(QCloseEvent* event) {
    // Save window state (position, size)
    QSettings settings("TeamPlemento", "TowerDefense");
    settings.setValue("geometry", saveGeometry());
    settings.setValue("windowState", saveState());
    QMainWindow::closeEvent(event);
}

}  // namespace view
