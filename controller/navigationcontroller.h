#ifndef CONTROLLER_NAVIGATIONCONTROLLER_H_
#define CONTROLLER_NAVIGATIONCONTROLLER_H_

#include <algorithm>

#include "routes.h"
#include "view/mainwindow.h"

using std::shared_ptr;

#define SP shared_ptr

namespace controller {

class NavigationController : public QObject {
    Q_OBJECT

   private:
    Routes _currentRoute;
    Routes _lastRoute;
    SP<view::MainWindow> _mainWindow;

   public:
    NavigationController(const SP<view::MainWindow> mainWindow);

   public slots:
    void navigateTo(Routes route);
    void back();
};

}  // namespace controller

#endif