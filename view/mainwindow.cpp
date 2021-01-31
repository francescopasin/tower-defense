#include "view/mainwindow.h"

#include <QApplication>
#include <QFontDatabase>
#include <QResizeEvent>
#include <QSettings>

#include "controller/gamescreencontroller.h"
#include "controller/initialscreencontroller.h"
#include "controller/setmapscreencontroller.h"

namespace view {

MainWindow::MainWindow(SP<model::GameModel> model) : _model(model), central(new QWidget()), centralLayout(new QVBoxLayout()), currentViewController(nullptr) {
    setWindowTitle("Tower Defense");

    setMinimumSize(QSize(1280, 720));
    resize(QSize(1280, 720));

    // Restore user settings
    readSettings();

    // Add fonts
    QFontDatabase::addApplicationFont(":/assets/fonts/PressStart2P-Regular.ttf");

    central->setLayout(centralLayout);
    centralLayout->setContentsMargins(0, 0, 0, 0);

    setCentralWidget(central);

    setScreen(app::Routes::InitialScreen);
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

void MainWindow::setScreen(app::Routes route) {
    if (currentViewController) {
        centralLayout->removeWidget(currentViewController->getView());

        delete currentViewController;
    }

    switch (route) {
        default:
        case app::Routes::InitialScreen:
            currentViewController = new controller::InitialScreenController(_model);
            break;
        case app::Routes::GameScreen:
            currentViewController = new controller::GameScreenController(_model);
            break;
        case app::Routes::SetMapScreen:
            currentViewController = new controller::SetMapScreenController(_model);
            break;
    }

    connect(currentViewController, &controller::Controller::navigateTo, this, &MainWindow::setScreen);

    centralLayout->addWidget(currentViewController->getView());
}

}  // namespace view
