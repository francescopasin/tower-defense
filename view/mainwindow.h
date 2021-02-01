#ifndef VIEW_MAINWINDOW_H_
#define VIEW_MAINWINDOW_H_

#include <QMainWindow>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <memory>
#include <vector>

#include "app/routes.h"
#include "controller/controller.h"
#include "model/gamemodel.h"

using std::shared_ptr;
using std::vector;

#define SP shared_ptr

namespace view {

class MainWindow : public QMainWindow {
    Q_OBJECT

   private:
    SP<model::GameModel> _model;
    QWidget *central;
    QVBoxLayout *centralLayout;
    controller::Controller *currentViewController;
    QString _error;

    void closeEvent(QCloseEvent *event) override;
    void readSettings();

   public:
    MainWindow(SP<model::GameModel> model, const QString &error = "");

   public slots:
    void setScreen(app::Routes route);
};

}  // namespace view

#endif