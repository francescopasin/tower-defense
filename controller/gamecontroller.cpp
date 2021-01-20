#include "gamecontroller.h"

#include <QDebug>

namespace controller {

GameController::GameController(const SP<model::GameModel>& model, const SP<view::GameScene>& view)
    : _model(model), _view(view) {
    // Connect view signals
    connect(view.get(), &view::GameScene::playPauseButtonPressed, this, &GameController::playPause);
    connect(view.get(), &view::GameScene::fastForwardButtonPressed, this, &GameController::fastForward);
}

void GameController::playPause() {
    qDebug() << "Play pause";
}

void GameController::fastForward() {
    qDebug() << "Fast forward";
}

}  // namespace controller