#ifndef CONTROLLER_GAMECONTROLLER_H_
#define CONTROLLER_GAMECONTROLLER_H_

#include <QTimer>
#include <memory>

#include "model/gamemodel.h"
#include "view/screens/gameScreen/gamescene.h"

using std::shared_ptr;

#define SP shared_ptr

namespace controller {

class GameController : public QObject {
    Q_OBJECT

   private:
    SP<model::GameModel> _model;
    SP<view::GameScene> _view;

    QTimer* gameTimer;
    QTimer* renderTimer;
    bool isRunning;
    bool isFastForward;

   public:
    GameController(const SP<model::GameModel>& model, const SP<view::GameScene>& view);

   public slots:
    void gameTick();
    void viewTick();

    void start();
    void playPause();
    void fastForward();
};

}  // namespace controller

#endif