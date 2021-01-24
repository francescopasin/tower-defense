#ifndef VIEW_MAINWINDOW_H_
#define VIEW_MAINWINDOW_H_

#include <QMainWindow>
#include <QStackedWidget>
#include <vector>

#include "routes.h"
#include "view/gameview.h"

using std::vector;

namespace view {

class MainWindow : public QMainWindow {
   private:
    QStackedWidget *stack;

    void closeEvent(QCloseEvent *event) override;
    void readSettings();

   public:
    MainWindow(const vector<QWidget *> &screens);

    void setScreen(Routes route);
};

}  // namespace view

#endif