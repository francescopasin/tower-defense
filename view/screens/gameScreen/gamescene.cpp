#include "view/screens/gameScreen/gamescene.h"

#include <QDebug>
#include <algorithm>

#include "view/hud/iconbutton.h"
#include "view/screens/gameScreen/gridfield.h"
#include "view/screens/gameScreen/pausemodal.h"

using std::vector;

namespace view {

GameScene::GameScene(const SP<const model::GameModel>& model) : _model(model), gridField(nullptr) {
    // Performance optimization
    setItemIndexMethod(QGraphicsScene::NoIndex);

    setSceneRect(0, 0, 1920, 1080);

    drawBackground();
    createHUD();

    turretSelector = new TurretSelector();
    connect(turretSelector, &TurretSelector::losedFocusSignal, this, &GameScene::closeTurretSelector);
    connect(turretSelector, &TurretSelector::turretSelected, this, &GameScene::addTurret);

    resetField();
}

void GameScene::drawBackground() {
    QBrush brush = QBrush(QColor::fromRgb(50, 50, 50));
    setBackgroundBrush(brush);
}

void GameScene::createHUD() {
    creditsInfo = new InfoBox(":/assets/images/coin.png", QString::number(_model->getCredits()));
    creditsInfo->setPos(10, 15);
    addItem(creditsInfo);

    lifeInfo = new InfoBox(":/assets/images/heart.png", QString::number(_model->getLife()));
    lifeInfo->setPos(10, 75);
    addItem(lifeInfo);

    IconButton* pauseButton = new IconButton(":/assets/images/pause-button-idle.png", ":/assets/images/pause-button-pressed.png");
    pauseButton->setPos(1400, 25);
    addItem(pauseButton);
    connect(pauseButton, &IconButton::pressed, this, &GameScene::pauseButtonPressed);

    IconButton* fastForwardButton = new IconButton(":/assets/images/fast-forward-button-idle.png", ":/assets/images/fast-forward-button-pressed.png");
    fastForwardButton->setPos(1550, 25);  // MAGIC NUMBER
    addItem(fastForwardButton);
    connect(fastForwardButton, &IconButton::pressed, this, &GameScene::fastForwardGame);

    // TODO: add menu (or back) button/signal
}

void GameScene::resetField() {
    // TODO: TEMP. Navigation should rebuild every view every time

    if (gridField) {
        removeItem(gridField);
        delete gridField;
    }

    gridField = new GridField(QSize(96 * 16, 96 * 9), _model->getMap(), _model->getBlockedCellsMap());
    gridField->setPos(0, 1080 - gridField->boundingRect().height());
    addItem(gridField);
    connect(gridField, &GridField::cellPressed, this, &GameScene::gridCellPressed);
}

void GameScene::tick() {
    // Update info
    creditsInfo->setText(QString::number(_model->getCredits()));
    lifeInfo->setText(QString::number(_model->getLife()));

    auto i = enemies.begin();
    while (i != enemies.end()) {
        if ((*i)->isDead()) {
            removeItem(*i);
            i = enemies.erase(i);
        } else {
            (*i)->tick();
            ++i;
        }
    }
}

void GameScene::spawnEnemy(const SP<model::Enemy>& enemy) {
    EnemyItem* en = new EnemyItem(gridField, enemy, 96);
    enemies.push_back(en);
}

void GameScene::addTurretItem(const model::SharedPtr<model::Turret>& turret, model::TurretType turretType) {
    closeTurretSelector();
    gridField->addTurretItem(turret, turretType);
}

void GameScene::gridCellPressed(GridCellType cellType, model::Position cellPosition) {
    if (cellType == GridCellType::Free) {
        turretSelector->setPos(
            qMax(cellPosition.x * 96 + 48 - turretSelector->boundingRect().width() / 2, 0.0),
            cellPosition.y * 96 - turretSelector->boundingRect().height() + 1080 - gridField->boundingRect().height());  // TODO: temp

        // TODO: set fixed cell size

        addItem(turretSelector);
        turretSelector->added(_model->getCredits());
    } else if (cellType == GridCellType::Occupied) {
        emit removeTurretSignal(cellPosition);
    }
}

void GameScene::closeTurretSelector() {
    removeItem(turretSelector);
    gridField->selectCell(nullptr);
}

void GameScene::addTurret(model::TurretType turretType) {
    // Get selected cell position
    model::Position position = gridField->getSelectedCellPosition();

    emit addTurretSignal(position, turretType);
}

void GameScene::updateGrid() {
    gridField->updateGrid();
}

void GameScene::pauseButtonPressed() {
    emit playPauseGame();

    PauseModal* modal = new PauseModal(width(), height());
    addItem(modal);
    connect(modal, &Modal::close, this, [=]() {
        removeItem(modal);
        delete modal;
        emit playPauseGame();
    });

    connect(modal, &PauseModal::returnToMenu, this, [=]() {
        removeItem(modal);
        delete modal;
        enemies.clear();
        emit returnToMenu();
    });

    // TODO: choose if create and delete modal everytime or add and remove it
}

}  // namespace view
