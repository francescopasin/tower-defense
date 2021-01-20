#include "gamecontroller.h"

namespace controller {

GameController::GameController(const SP<model::GameModel>& model, const SP<view::GameView>& view)
    : _model(model), _view(view) {}

}  // namespace controller