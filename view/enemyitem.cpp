#include "view/enemyitem.h"

#include <QPainter>

namespace view {

EnemyItem::EnemyItem(const SP<model::Enemy> &enemy, qreal cellSize) : enemyData(enemy), _cellSize(cellSize) {
    setPosition();
}

void EnemyItem::setPosition() {
    model::PathCell currentCell = enemyData->getCurrentCell();
    float cellPosition = enemyData->getCellPosition();
    bool firstHalf = cellPosition < 50;

    qreal x = currentCell.x * _cellSize;
    qreal y = currentCell.y * _cellSize;

    // Get direction
    switch (currentCell.from) {
        case model::Direction::Left:
            switch (currentCell.to) {
                case model::Direction::Up:
                    if (firstHalf) {
                        x += cellPosition * _cellSize / 100;
                    } else {
                        y -= cellPosition * _cellSize / 100;
                    }
                    break;
                case model::Direction::Right:
                    x += cellPosition * _cellSize / 100;
                    break;
                case model::Direction::Down:
                    if (firstHalf) {
                        x += cellPosition * _cellSize / 100;
                    } else {
                        y += cellPosition * _cellSize / 100;
                    }
                    break;
            }
            break;
        case model::Direction::Up:
            switch (currentCell.to) {
                case model::Direction::Left:
                    if (firstHalf) {
                        y += cellPosition * _cellSize / 100;
                    } else {
                        x -= cellPosition * _cellSize / 100;
                    }
                    break;
                case model::Direction::Right:
                    if (firstHalf) {
                        y += cellPosition * _cellSize / 100;
                    } else {
                        x += cellPosition * _cellSize / 100;
                    }
                    break;
                case model::Direction::Down:
                    y += cellPosition * _cellSize / 100;
                    break;
            }
            break;
        case model::Direction::Right:
            switch (currentCell.to) {
                case model::Direction::Left:
                    x -= cellPosition * _cellSize / 100;
                    break;
                case model::Direction::Up:
                    if (firstHalf) {
                        x -= cellPosition * _cellSize / 100;
                    } else {
                        y -= cellPosition * _cellSize / 100;
                    }
                    break;
                case model::Direction::Down:
                    if (firstHalf) {
                        x -= cellPosition * _cellSize / 100;
                    } else {
                        y += cellPosition * _cellSize / 100;
                    }
                    break;
            }
            break;
        case model::Direction::Down:
            switch (currentCell.to) {
                case model::Direction::Left:
                    if (firstHalf) {
                        y -= cellPosition * _cellSize / 100;
                    } else {
                        x -= cellPosition * _cellSize / 100;
                    }
                    break;
                case model::Direction::Up:
                    y -= cellPosition * _cellSize / 100;
                    break;
                case model::Direction::Right:
                    if (firstHalf) {
                        y -= cellPosition * _cellSize / 100;
                    } else {
                        x += cellPosition * _cellSize / 100;
                    }
                    break;
            }
            break;
    }

    setPos(x, y);
}

QRectF EnemyItem::boundingRect() const {
    return QRectF(0, 0, 50, 50);
}

void EnemyItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::red);

    painter->drawRect(0, 0, 50, 50);
}

void EnemyItem::tick() {
    // Update position
    setPosition();

    // TODO: check health

    update();
}

}  // namespace view
