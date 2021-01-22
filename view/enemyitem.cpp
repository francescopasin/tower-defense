#include "view/enemyitem.h"

#include <QPainter>

namespace view {

EnemyItem::EnemyItem(
    QGraphicsItem *parent,
    const SP<model::Enemy> &enemy,
    qreal cellSize)
    : QGraphicsItem(parent),
      enemyData(enemy),
      _cellSize(cellSize) {
    setPosition();
}

void EnemyItem::setPosition() {
    model::PathCell currentCell = enemyData->getCurrentCell();
    float cellPosition = enemyData->getCellPosition();
    bool firstHalf = cellPosition < 50;

    qreal x = currentCell.x * _cellSize;
    qreal y = currentCell.y * _cellSize;

    // Get direction
    if (firstHalf) {
        switch (currentCell.from) {
            case model::Direction::Left:
                x += cellPosition * _cellSize / 100;
                y += _cellSize / 2;
                break;
            case model::Direction::Up:
                x += _cellSize / 2;
                y += cellPosition * _cellSize / 100;
                break;
            case model::Direction::Right:
                x -= cellPosition * _cellSize / 100;
                y += _cellSize / 2;
                break;
            case model::Direction::Down:
                x += _cellSize / 2;
                y -= cellPosition * _cellSize / 100 - _cellSize;
                break;
        }
    } else {
        switch (currentCell.to) {
            case model::Direction::Left:
                x -= cellPosition * _cellSize / 100;
                y += _cellSize / 2;
                break;
            case model::Direction::Up:
                x += _cellSize / 2;
                y -= cellPosition * _cellSize / 100 - _cellSize;
                break;
            case model::Direction::Right:
                x += cellPosition * _cellSize / 100;
                y += _cellSize / 2;
                break;
            case model::Direction::Down:
                x += _cellSize / 2;
                y += cellPosition * _cellSize / 100;
                break;
        }
    }

    // 15 = enemy size / 2 - align to center
    x -= 15;
    y -= 15;

    setPos(x, y);
}

QRectF EnemyItem::boundingRect() const {
    return QRectF(0, 0, 30, 30);
}

void EnemyItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::red);

    painter->drawRect(0, 0, 30, 30);
}

void EnemyItem::tick() {
    // Update position
    setPosition();

    // TODO: check health

    update();
}

}  // namespace view
