#include "view/gamescene.h"

#include <QGraphicsRectItem>
#include <QRandomGenerator>

#include "view/gridcell.h"
#include "view/hud/iconbutton.h"
#include "view/hud/infobox.h"
#include "view/hud/turretselector.h"

namespace view {

GameScene::GameScene(const SP<const model::GameModel>& model) : _model(model) {
    // Performance optimization
    setItemIndexMethod(QGraphicsScene::NoIndex);

    setSceneRect(0, 0, 1920, 1080);

    drawBackground();
    createGameGrid();
    createHUD();
}

void GameScene::drawBackground() {
    QBrush brush = QBrush(QColor::fromRgb(50, 50, 50));
    setBackgroundBrush(brush);
}

void GameScene::createGameGrid() {
    // TODO: get info from model
    qreal size = 96;

    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 9; j++) {
            GridCell* cell;

            if (j == 4) {
                if (i == 0) {
                    cell = new GridCell(size, GridCellType::PathStart);
                } else if (i == 15) {
                    cell = new GridCell(size, GridCellType::PathEnd, PathGridCellTile::Right);
                } else {
                    // TODO set path tile type based on PathCell direction from and to
                    cell = new GridCell(size, GridCellType::Path);
                }

            } else {
                if (QRandomGenerator::global()->bounded(3) == 1) {
                    cell = new GridCell(size, GridCellType::Blocked);
                } else {
                    cell = new GridCell(size);
                }
            }

            cell->setPos(i * size, j * size + (1080 - size * 9));
            addItem(cell);
        }
    }
}

void GameScene::createHUD() {
    // TODO: get info from model
    InfoBox* infoBox = new InfoBox(":/assets/images/coin.png", "10");
    infoBox->setPos(10, 15);
    addItem(infoBox);

    InfoBox* infoBox2 = new InfoBox(":/assets/images/heart.png", "90%");
    infoBox2->setPos(10, 75);
    addItem(infoBox2);

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
}

}  // namespace view
