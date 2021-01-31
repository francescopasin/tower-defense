#include "controller/controller.h"

namespace controller {

Controller::Controller(const SP<model::GameModel>& model) : _model(model) {}

Controller::~Controller() {}

QGraphicsView* Controller::getView() const {
    return _view;
}

}  // namespace controller
