#ifndef VIEW_MAINWINDOW_H_
#define VIEW_MAINWINDOW_H_

#include <QMainWindow>

#include "view/gameview.h"

namespace view {

class MainWindow : public QMainWindow {
    Q_OBJECT

   private:
    GameView *gameView;

    void closeEvent(QCloseEvent *event) override;
    void readSettings();

   public:
    MainWindow(QWidget *parent = nullptr);
};

}  // namespace view

#endif