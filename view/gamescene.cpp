#include "view/gamescene.h"

#include <QDebug>
#include <QGraphicsRectItem>
#include <QRandomGenerator>

#include "view/gridcell.h"

namespace view {

GameScene::GameScene(qreal width, qreal height) {
    setSceneRect(0, 0, width, height);

    // Performance optimization
    setItemIndexMethod(QGraphicsScene::NoIndex);

    drawBackground();
    createGameGrid();
}

void GameScene::drawBackground() {
    QBrush brush = QBrush(QColor::fromRgb(50, 50, 50));
    setBackgroundBrush(brush);
}

void GameScene::createGameGrid() {
    // TODO: get info from model

    qreal sizeW = width() / 15;
    qreal sizeH = height() / 10;

    qreal size = qMin<qreal>(sizeW, sizeH);

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 10; j++) {
            int value = QRandomGenerator::global()->bounded(2);

            GridCell *cell;

            if (value == 1) {
                cell = new GridCell(size, true);
            } else {
                cell = new GridCell(size);
            }

            cell->setPos(i * size, j * size);
            addItem(cell);
        }
    }

    qDebug() << width() << " " << height();
}

}  // namespace view
