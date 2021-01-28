#include "view/screens/gameScreen/turretselector.h"

#include <QCursor>
#include <QPainter>

#include "model/turrets/turrettype.h"
#include "view/screens/gameScreen/turretselectoritem.h"

namespace view {

TurretSelector::TurretSelector() {
    setFlag(QGraphicsItem::ItemIsFocusable);

    QPixmap pixmap = QPixmap(":/assets/images/pointer.png");
    setCursor(QCursor(pixmap.scaled(32, 32)));

    TurretSelectorItem *weakTurretSelector = new TurretSelectorItem(this, model::TurretType::WeakTurret);
    weakTurretSelector->setPos(10, 10);
    connect(weakTurretSelector, &TurretSelectorItem::pressed, this, [=]() { emit turretSelected(model::TurretType::WeakTurret); });

    TurretSelectorItem *mitraTurretSelector = new TurretSelectorItem(this, model::TurretType::MitraTurret);
    mitraTurretSelector->setPos(110, 10);
    connect(mitraTurretSelector, &TurretSelectorItem::pressed, this, [=]() { emit turretSelected(model::TurretType::MitraTurret); });

    TurretSelectorItem *granadeTurretSelector = new TurretSelectorItem(this, model::TurretType::GranadeTurret);
    granadeTurretSelector->setPos(210, 10);
    connect(granadeTurretSelector, &TurretSelectorItem::pressed, this, [=]() { emit turretSelected(model::TurretType::GranadeTurret); });

    TurretSelectorItem *comboTurretSelector = new TurretSelectorItem(this, model::TurretType::ComboTurret);
    comboTurretSelector->setPos(310, 10);
    connect(comboTurretSelector, &TurretSelectorItem::pressed, this, [=]() { emit turretSelected(model::TurretType::ComboTurret); });

    TurretSelectorItem *splitTurretSelector = new TurretSelectorItem(this, model::TurretType::SplitTurret);
    splitTurretSelector->setPos(410, 10);
    connect(splitTurretSelector, &TurretSelectorItem::pressed, this, [=]() { emit turretSelected(model::TurretType::SplitTurret); });
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

void TurretSelector::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    // To prevent clicks below
}

void TurretSelector::focusOutEvent(QFocusEvent *event) {
    emit losedFocusSignal();
}

}  // namespace view