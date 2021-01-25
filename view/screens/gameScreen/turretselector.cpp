#include "view/screens/gameScreen/turretselector.h"

#include <QPainter>

#include "model/turrets/turrettype.h"
#include "view/screens/gameScreen/turretselectoritem.h"

namespace view {

TurretSelector::TurretSelector() {
    TurretSelectorItem *selectorItem1 = new TurretSelectorItem(this, model::TurretType::WeakTurret);
    selectorItem1->setPos(10, 10);

    TurretSelectorItem *selectorItem2 = new TurretSelectorItem(this, model::TurretType::MitraTurret);
    selectorItem2->setPos(110, 10);

    TurretSelectorItem *selectorItem3 = new TurretSelectorItem(this, model::TurretType::GranadeTurret);
    selectorItem3->setPos(210, 10);

    TurretSelectorItem *selectorItem4 = new TurretSelectorItem(this, model::TurretType::ComboTurret);
    selectorItem4->setPos(310, 10);

    TurretSelectorItem *selectorItem5 = new TurretSelectorItem(this, model::TurretType::SplitTurret);
    selectorItem5->setPos(410, 10);
}

QRectF TurretSelector::boundingRect() const {
    return QRectF(0, 0, 500, 100);
}

void TurretSelector::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QPen pen;
    pen.setColor(Qt::black);
    pen.setWidth(5);

    painter->setPen(pen);
    painter->setBrush(QBrush(QColor::fromRgb(70, 70, 70)));
    painter->drawRect(0, 0, 500, 100);
}

}  // namespace view
