#include "gamecontroller.h"

namespace controller {

GameController::GameController(const SP<model::GameModel>& model, const SP<view::GameScene>& view)
    : _model(model), _view(view), isRunning(false) {
    // Connect view signals
    connect(view.get(), &view::GameScene::playPauseButtonPressed, this, &GameController::playPause);
    connect(view.get(), &view::GameScene::fastForwardButtonPressed, this, &GameController::fastForward);
}

void GameController::gameTick() {
    _model->tick();
}

void GameController::viewTick() {
    _view->tick();
}

void GameController::start() {
    gameTimer = new QTimer(this);
    connect(gameTimer, &QTimer::timeout, this, &GameController::gameTick);
    // 20 ticks per second
    // TODO: safe default tick in Game?
    gameTimer->start(1 / 20 * 1000);

    renderTimer = new QTimer(this);
    connect(renderTimer, &QTimer::timeout, this, &GameController::viewTick);
    // 24 ticks per second
    renderTimer->start(1 / 24 * 1000);
}

void GameController::playPause() {
    if (isRunning) {
        gameTimer->stop();
        renderTimer->stop();
    } else {
        gameTimer->start();
        renderTimer->start();
    }

    isRunning = !isRunning;
}

void GameController::fastForward() {
    if (gameTimer->interval() == 1 / 20 * 1000) {
        // 40 ticks per second
        gameTimer->setInterval(1 / 40 * 1000);
    } else {
        // 20 ticks per second
        gameTimer->setInterval(1 / 20 * 1000);
    }
}

}  // namespace controller