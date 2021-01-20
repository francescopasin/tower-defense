#ifndef CONTROLLER_GAMECONTROLLER_H_
#define CONTROLLER_GAMECONTROLLER_H_

#include <memory>

#include "model/gamemodel.h"
#include "view/gameview.h"

using std::shared_ptr;

#define SP shared_ptr

namespace controller {

class GameController {
   private:
    SP<model::GameModel> _model;
    SP<view::GameView> _view;

   public:
    GameController(const SP<model::GameModel>& model, const SP<view::GameView>& view);
};

}  // namespace controller

#endif