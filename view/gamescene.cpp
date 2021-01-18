#include "view/gamescene.h"

#include <QGraphicsRectItem>
#include <QRandomGenerator>

#include "view/gridcell.h"
#include "view/hud/iconbutton.h";
#include "view/hud/infobox.h"

namespace view {

GameScene::GameScene() {
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
    qreal toolbarHeight = 150;

    qreal size = (height() - toolbarHeight) / 9;

    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 9; j++) {
            int value = QRandomGenerator::global()->bounded(2);

            GridCell* cell;

            if (value == 1) {
                cell = new GridCell(size, true);
            } else {
                cell = new GridCell(size);
            }

            cell->setPos(i * size, j * size + toolbarHeight);
            addItem(cell);
        }
    }
}

void GameScene::createHUD() {
    InfoBox* infoBox = new InfoBox(":/assets/images/coin.png", "10");
    infoBox->setPos(10, 15);
    addItem(infoBox);

    InfoBox* infoBox2 = new InfoBox(":/assets/images/heart.png", "90%");
    infoBox2->setPos(10, 75);
    addItem(infoBox2);

    IconButton* playPauseButton = new IconButton(":/assets/images/play-button-idle.png", ":/assets/images/play-button-pressed.png");
    playPauseButton->setPos(1400, 25);
    addItem(playPauseButton);

    IconButton* fastForwardButton = new IconButton(":/assets/images/fast-forward-button-idle.png", ":/assets/images/fast-forward-button-pressed.png");
    fastForwardButton->setPos(1550, 25);  // MAGIC NUMBER
    addItem(fastForwardButton);
}

}  // namespace view
