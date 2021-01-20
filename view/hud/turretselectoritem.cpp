#include "view/hud/turretselectoritem.h"

#include <QPainter>

namespace view {

TurretSelectorItem::TurretSelectorItem(QGraphicsItem *parent) : QGraphicsItem(parent) {}

QRectF TurretSelectorItem::boundingRect() const {
    return QRectF(0, 0, 230, 200);
}

void TurretSelectorItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(Qt::NoPen);
    painter->setBrush(QBrush(QColor::fromRgb(100, 100, 100)));
    painter->drawRect(0, 0, 230, 200);
}

}  // namespace view
