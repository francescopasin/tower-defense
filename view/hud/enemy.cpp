#include "view/hud/enemy.h"

#include <QPainter>

namespace view {

Enemy::Enemy() {
}

QRectF Enemy::boundingRect() const {
    return QRectF(0, 0, 50, 50);
}

void Enemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::red);

    painter->drawRect(0, 0, 50, 50);
}

}  // namespace view
