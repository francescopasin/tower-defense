#include "controller/navigationcontroller.h"

namespace controller {

NavigationController::NavigationController(const SP<view::MainWindow> mainWindow)
    : _currentRoute(Routes::InitialScreen),
      _lastRoute(_currentRoute),
      _mainWindow(mainWindow) {}

void NavigationController::navigateTo(Routes route) {
    _lastRoute = _currentRoute;
    _currentRoute = route;

    _mainWindow->setScreen(_currentRoute);
}

void NavigationController::back() {
    std::swap(_currentRoute, _lastRoute);

    _mainWindow->setScreen(_currentRoute);
}

}  // namespace controller
