#include "controller/gamecontroller.h"

#include "model/sharedptr.h"
#include "model/turrets/turret.h"

namespace controller {

GameController::GameController(
    const SP<model::GameModel>& model,
    const SP<view::GameScene>& view)
    : _model(model),
      _view(view),
      isRunning(false),
      isFastForward(false) {}

void GameController::gameTick() {
    _model->tick();

    SP<model::Enemy> newEnemy = _model->lastTickSpawnedEnemy();
    if (newEnemy) {
        _view->spawnEnemy(newEnemy);
    }
}

void resetGame() {
    _model->reset();
}

void GameController::viewTick() {
    _view->tick();
}

void GameController::start() {
    gameTimer = new QTimer(this);
    connect(gameTimer, &QTimer::timeout, this, &GameController::gameTick);
    // 20 ticks per second
    // TODO: safe default tick in Game?
    gameTimer->start(1 / 24.00 * 1000);

    renderTimer = new QTimer(this);
    connect(renderTimer, &QTimer::timeout, this, &GameController::viewTick);
    // 20 ticks per second
    renderTimer->start(1 / 24.00 * 1000);
}

void GameController::playPause() {
    if (isRunning) {
        gameTimer->stop();
        renderTimer->stop();
    } else {
        // TODO: temp. remove this
        start();

        gameTimer->start();
        renderTimer->start();
    }

    isRunning = !isRunning;
}

void GameController::fastForward() {
    gameTimer->stop();

    if (!isFastForward) {
        // 48 ticks per second
        gameTimer->setInterval(1 / 48.00 * 1000);
    } else {
        // 24 ticks per second
        gameTimer->setInterval(1 / 24.00 * 1000);
    }

    isFastForward = !isFastForward;
    gameTimer->start();
}

void GameController::addTurret(model::Position position, model::TurretType turretType) {
    model::SharedPtr<model::Turret> turret = _model->addTurret(turretType, position);

    _view->addTurretItem(turret, turretType);
}

void GameController::removeTurret(model::Position position) {
    _model->removeTurret(position);
}

}  // namespace controller