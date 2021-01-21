#include "view/enemyitem.h"

#include <QPainter>

namespace view {

EnemyItem::EnemyItem(const SP<model::Enemy> &enemy, qreal cellSize) : enemyData(enemy), _cellSize(cellSize) {
    // TODO: consider also enemyData::cellPosition
    setPos(enemyData->getPosition().x * _cellSize, enemyData->getPosition().y * _cellSize);
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

}  // namespace view
