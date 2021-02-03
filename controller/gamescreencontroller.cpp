#include "controller/gamescreencontroller.h"

#include <vector>

#include "model/sharedptr.h"
#include "model/turrets/turret.h"

using std::vector;

namespace controller {

GameScreenController::GameScreenController(const SP<model::GameModel>& model)
    : Controller(model), isRunning(false), isFastForward(false) {
    _scene = new view::GameScene(model);

    connect(
        _scene,
        &view::GameScene::playPauseGame,
        this,
        &controller::GameScreenController::playPause);

    connect(
        _scene,
        &view::GameScene::returnToMenu,
        this,
        &controller::GameScreenController::returnToMenu);

    connect(
        _scene,
        &view::GameScene::fastForwardGame,
        this,
        &controller::GameScreenController::fastForward);

    connect(
        _scene,
        &view::GameScene::addTurretSignal,
        this,
        &controller::GameScreenController::addTurret);

    connect(
        _scene,
        &view::GameScene::removeTurretSignal,
        this,
        &controller::GameScreenController::removeTurret);

    connect(
        _scene,
        &view::GameScene::restart,
        this,
        &GameScreenController::restart);

    start();
}

QGraphicsScene* GameScreenController::getScene() const {
    return _scene;
}

void GameScreenController::start() {
    gameTimer = new QTimer(this);
    connect(gameTimer, &QTimer::timeout, this, &GameScreenController::gameTick);
    // 20 ticks per second
    // TODO: safe default tick in Game?
    gameTimer->start(1 / 24.00 * 1000);

    renderTimer = new QTimer(this);
    connect(renderTimer, &QTimer::timeout, this, &GameScreenController::viewTick);
    // 20 ticks per second
    renderTimer->start(1 / 24.00 * 1000);

    isRunning = true;
}

void GameScreenController::gameTick() {
    model::Game::State stato = _model->tick();

    if (stato == model::Game::State::Lost || stato == model::Game::State::Won) {
        gameTimer->stop();
        renderTimer->stop();
        _scene->showModal(stato);
    }

    SP<model::Enemy> newEnemy = _model->lastTickSpawnedEnemy();
    vector<SP<model::Turret>> lastTickAttackingTurrets = _model->lastTickAttackingTurrets();

    if (newEnemy) {
        _scene->spawnEnemy(newEnemy);
    }

    if (lastTickAttackingTurrets.size() > 0) {
        _scene->turretsAttack(lastTickAttackingTurrets);
    }
}

void GameScreenController::returnToMenu() {
    _model->reset();

    emit navigateTo(app::Routes::InitialScreen);
}

void GameScreenController::restart() {
    _model->reset();

    emit navigateTo(app::Routes::GameScreen);
}

void GameScreenController::viewTick() {
    _scene->tick();
}

void GameScreenController::playPause() {
    if (isRunning) {
        gameTimer->stop();
        renderTimer->stop();
    } else {
        gameTimer->start();
        renderTimer->start();
    }

    isRunning = !isRunning;
}

void GameScreenController::fastForward() {
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

void GameScreenController::addTurret(model::Position position, model::TurretType turretType) {
    SP<model::Turret> turret = _model->addTurret(turretType, position);

    _scene->addTurretItem(turret, turretType);
}

void GameScreenController::removeTurret(model::Position position) {
    _model->removeTurret(position);
}

}  // namespace controller
