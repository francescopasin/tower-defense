#include "view/gamescene.h"

#include <algorithm>

#include "view/gridfield.h"
#include "view/hud/iconbutton.h"
#include "view/hud/turretselector.h"

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

    TurretSelector* turretSelector = new TurretSelector();
    turretSelector->setPos(1670, 150);  // 1670 = 1920 - 250
    addItem(turretSelector);

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

}  // namespace view
