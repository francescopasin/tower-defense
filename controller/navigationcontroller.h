#ifndef CONTROLLER_NAVIGATIONCONTROLLER_H_
#define CONTROLLER_NAVIGATIONCONTROLLER_H_

#include <algorithm>

#include "app/routes.h"
#include "view/mainwindow.h"

using std::shared_ptr;

#define SP shared_ptr

namespace controller {

class NavigationController : public QObject {
    Q_OBJECT

   private:
    app::Routes _currentRoute;
    app::Routes _lastRoute;
    SP<view::MainWindow> _mainWindow;

   public:
    NavigationController(const SP<view::MainWindow> mainWindow);

   public slots:
    void navigateTo(app::Routes route);
    void back();
};

}  // namespace controller

#endif