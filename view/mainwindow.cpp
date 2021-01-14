#include "mainwindow.h"

#include <QDebug>
#include <QFontDatabase>
#include <QGraphicsRectItem>
#include <QMenuBar>
#include <QResizeEvent>
#include <QSettings>
#include <QVBoxLayout>

namespace view {

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle("Tower Defense");

    createActions();
    createMenu();

    setMinimumSize(QSize(1280, 720));
    resize(QSize(1280, 720));

    // Restore user settings
    readSettings();

    // Add fonts
    QFontDatabase::addApplicationFont(":/assets/fonts/RobotoMono-Regular.ttf");
    QFontDatabase::addApplicationFont(":/assets/fonts/RobotoMono-SemiBold.ttf");

    gameView = new GameView();

    setCentralWidget(gameView);
}

/*
void MainWindow::resizeEvent(QResizeEvent *event) {
    QMainWindow::resizeEvent(event);

    // Resize the game view
    gameView->setBaseSize(event->size());
}
*/

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

void MainWindow::createActions() {
    closeAct = new QAction("&Close", this);
    closeAct->setShortcuts(QKeySequence::Close);
    connect(closeAct, &QAction::triggered, this, &MainWindow::close);
}

void MainWindow::createMenu() {
    QMenu *file = menuBar()->addMenu("&File");
    file->addAction(closeAct);
}

}  // namespace view
