#ifndef CONTROLLER_GAMECONTROLLER_H_
#define CONTROLLER_GAMECONTROLLER_H_

#include <memory>

#include "model/gamemodel.h"
#include "view/gamescene.h"

using std::shared_ptr;

#define SP shared_ptr

namespace controller {

class GameController : public QObject {
    Q_OBJECT

   private:
    SP<model::GameModel> _model;
    SP<view::GameScene> _view;

   public:
    GameController(const SP<model::GameModel>& model, const SP<view::GameScene>& view);

   public slots:
    void playPause();
    void fastForward();
};

}  // namespace controller

#endif