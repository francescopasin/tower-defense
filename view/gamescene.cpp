#include "view/gamescene.h"

#include <QGraphicsRectItem>
#include <QRandomGenerator>

#include "view/gridcell.h"

namespace view {

GameScene::GameScene() {
    // Performance optimization
    setItemIndexMethod(QGraphicsScene::NoIndex);

    setSceneRect(0, 0, 1920, 1080);

    drawBackground();
    createGameGrid();
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

            GridCell *cell;

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

}  // namespace view
