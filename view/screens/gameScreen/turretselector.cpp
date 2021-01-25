#include "view/screens/gameScreen/turretselector.h"

#include <QPainter>

#include "view/screens/gameScreen/turretselectoritem.h"

namespace view {

TurretSelector::TurretSelector() {
    TurretSelectorItem *selectorItem1 = new TurretSelectorItem(this);
    selectorItem1->setPos(10, 10);
}

QRectF TurretSelector::boundingRect() const {
    return QRectF(0, 0, 300, 100);
}

void TurretSelector::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QPen pen;
    pen.setColor(Qt::black);
    pen.setWidth(5);

    painter->setPen(pen);
    painter->setBrush(QBrush(QColor::fromRgb(70, 70, 70)));
    painter->drawRect(0, 0, 300, 100);
}

}  // namespace view
