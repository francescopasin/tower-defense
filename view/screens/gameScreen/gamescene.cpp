#include "view/screens/gameScreen/gamescene.h"

#include <QDebug>
#include <algorithm>

#include "view/hud/iconbutton.h"
#include "view/screens/gameScreen/gridfield.h"

using std::vector;

namespace view {

GameScene::GameScene(const SP<const model::GameModel>& model) : _model(model) {
    // Performance optimization
    setItemIndexMethod(QGraphicsScene::NoIndex);

    setSceneRect(0, 0, 1920, 1080);

    drawBackground();
    createHUD();

    gridField = new GridField(QSize(96 * 16, 96 * 9), _model->getMap(), _model->getBlockedCellsMap());
    gridField->setPos(0, 1080 - gridField->boundingRect().height());
    addItem(gridField);
    connect(gridField, &GridField::cellPressed, this, &GameScene::gridCellPressed);

    turretSelector = new TurretSelector();
    connect(turretSelector, &TurretSelector::losedFocusSignal, this, &GameScene::closeTurretSelector);
    connect(turretSelector, &TurretSelector::turretSelected, this, &GameScene::addTurret);
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

    IconButton* playPauseButton = new IconButton(":/assets/images/play-button-idle.png", ":/assets/images/play-button-pressed.png");
    playPauseButton->setPos(1400, 25);
    addItem(playPauseButton);
    connect(playPauseButton, &IconButton::pressed, this, &GameScene::playPauseButtonPressed);

    IconButton* fastForwardButton = new IconButton(":/assets/images/fast-forward-button-idle.png", ":/assets/images/fast-forward-button-pressed.png");
    fastForwardButton->setPos(1550, 25);  // MAGIC NUMBER
    addItem(fastForwardButton);
    connect(fastForwardButton, &IconButton::pressed, this, &GameScene::fastForwardButtonPressed);

    // TODO: add addturret signal
    // TODO: add removeturret signal
    // TODO: add menu (or back) button/signal
}

void GameScene::tick() {
    // Update info
    creditsInfo->setText(QString::number(_model->getCredits()));
    lifeInfo->setText(QString::number(_model->getLife()));

    for (auto i = enemies.begin(); i != enemies.end(); i++) {
        if ((*i)->isDead()) {
            removeItem(*i);
            i = enemies.erase(i) - 1;
        } else {
            (*i)->tick();
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

}  // namespace view
