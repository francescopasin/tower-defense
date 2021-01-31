#include "view/screens/gameScreen/projectile.h"

#include <QPainter>

namespace view {

Projectile::Projectile(QGraphicsItem *parent, const QPointF &startingPos, const QPointF &endingPos)
    : QGraphicsItem(parent), currentStep(1) {
    setPos(startingPos);

    deltaX = 1.0 / speed * (endingPos.x() - startingPos.x());
    deltaY = 1.0 / speed * (endingPos.y() - startingPos.y());
}

QRectF Projectile::boundingRect() const {
    return QRectF(0, 0, 10, 10);
}

void Projectile::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setBrush(Qt::red);
    painter->drawRect(0, 0, 10, 10);
}

bool Projectile::move() {
    // Calculate next point
    QPointF currentPos = pos();
    QPointF nextPos(currentPos.x() + deltaX, currentPos.y() + deltaY);

    if (currentStep == speed) {
        // Return true if arrived
        return true;
    }

    currentStep++;
    setPos(nextPos);
    update();

    return false;
}

}  // namespace view
