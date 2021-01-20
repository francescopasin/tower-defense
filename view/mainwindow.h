#ifndef VIEW_MAINWINDOW_H_
#define VIEW_MAINWINDOW_H_

#include <QMainWindow>

#include "view/gameview.h"

namespace view {

class MainWindow : public QMainWindow {
    Q_OBJECT

   private:
    void closeEvent(QCloseEvent *event) override;
    void readSettings();

   public:
    MainWindow(const SP<model::GameModel> &model, const SP<GameView> &gameView);
};

}  // namespace view

#endif