#include "view/hud/turretselector.h"

#include <QPainter>

#include "view/hud/turretselectoritem.h"

namespace view {

TurretSelector::TurretSelector() {
    TurretSelectorItem *selectorItem1 = new TurretSelectorItem(this);
    selectorItem1->setPos(10, 10);
}

QRectF TurretSelector::boundingRect() const {
    return QRectF(0, 0, 250, 930);
}

void TurretSelector::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(Qt::NoPen);
    painter->setBrush(QBrush(QColor::fromRgb(70, 70, 70)));
    painter->drawRect(0, 0, 250, 930);
}

}  // namespace view
