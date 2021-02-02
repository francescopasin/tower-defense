#include "view/mainwindow.h"

#include <QApplication>
#include <QFontDatabase>
#include <QResizeEvent>
#include <QSettings>

#include "controller/gamescreencontroller.h"
#include "controller/initialscreencontroller.h"
#include "controller/setmapscreencontroller.h"
#include "controller/tutorialscreencontroller.h"

namespace view {

MainWindow::MainWindow(SP<model::GameModel> model) : _model(model), view(new MainWindowView()), currentViewController(nullptr) {
    setWindowTitle("Tower Defense");

    setMinimumSize(QSize(1280, 720));
    resize(QSize(1280, 720));

    // Restore user settings
    readSettings();

    // Add fonts
    QFontDatabase::addApplicationFont(":/assets/fonts/PressStart2P-Regular.ttf");

    setCentralWidget(view);

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

void MainWindow::setTutorialShown() const {
    if (!tutorialHasBeenShown()) {
        QSettings settings("TeamPlemento", "TowerDefense");
        settings.setValue("tutorial", true);
    }
}

bool MainWindow::tutorialHasBeenShown() const {
    QSettings settings("TeamPlemento", "TowerDefense");
    return settings.value("tutorial", false).toBool();
}

void MainWindow::setScreen(app::Routes route) {
    if (currentViewController) {
        // TODO: understand how to correctly delete the scene
        view->scene()->setParent(nullptr);
        delete view->scene();
        view->setScene(nullptr);

        delete currentViewController;
    }

    switch (route) {
        default:
        case app::Routes::InitialScreen:
            currentViewController = new controller::InitialScreenController(_model);
            break;
        case app::Routes::TutorialScreen:
            currentViewController = new controller::TutorialScreenController(_model);
            setTutorialShown();
            break;
        case app::Routes::GameScreen:
            if (!tutorialHasBeenShown()) {
                currentViewController = new controller::TutorialScreenController(_model);
                setTutorialShown();
            } else {
                currentViewController = new controller::GameScreenController(_model);
            }
            break;
        case app::Routes::SetMapScreen:
            currentViewController = new controller::SetMapScreenController(_model);
            break;
    }

    connect(currentViewController, &controller::Controller::navigateTo, this, &MainWindow::setScreen);

    view->setScene(currentViewController->getScene());
}  // namespace view

}  // namespace view
