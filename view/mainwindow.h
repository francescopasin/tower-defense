#ifndef VIEW_MAINWINDOW_H_
#define VIEW_MAINWINDOW_H_

#include <QMainWindow>

#include "view/gameview.h"

namespace view {

class MainWindow : public QMainWindow {
    Q_OBJECT

   private:
    GameView *gameView;

    // Menu entries
    QMenu *fileMenu;

    // Menu actions
    QAction *closeAct;

    void closeEvent(QCloseEvent *event) override;
    void readSettings();
    void createActions();
    void createMenu();
    /*
   protected:
    void resizeEvent(QResizeEvent *event) override;
*/
   public:
    MainWindow(QWidget *parent = nullptr);
};

}  // namespace view

#endif