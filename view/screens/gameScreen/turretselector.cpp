#include "view/screens/gameScreen/turretselector.h"

#include <QCursor>
#include <QPainter>

namespace view {

TurretSelector::TurretSelector() {
    setFlag(QGraphicsItem::ItemIsFocusable);

    QPixmap pixmap = QPixmap(":/assets/images/pointers/pointer.png");
    setCursor(QCursor(pixmap.scaled(32, 32)));

    weakTurretSelector = new PopupSelectorItem(this, ":/assets/images/turrets/weak-turret.png");
    weakTurretSelector->setPos(10, 10);
    connect(weakTurretSelector, &PopupSelectorItem::pressed, this, [=]() { emit turretSelected(model::TurretType::WeakTurret); });

    mitraTurretSelector = new PopupSelectorItem(this, ":/assets/images/turrets/mitra-turret.png");
    mitraTurretSelector->setPos(110, 10);
    connect(mitraTurretSelector, &PopupSelectorItem::pressed, this, [=]() { emit turretSelected(model::TurretType::MitraTurret); });

    granadeTurretSelector = new PopupSelectorItem(this, ":/assets/images/turrets/granade-turret.png");
    granadeTurretSelector->setPos(210, 10);
    connect(granadeTurretSelector, &PopupSelectorItem::pressed, this, [=]() { emit turretSelected(model::TurretType::GranadeTurret); });

    comboTurretSelector = new PopupSelectorItem(this, ":/assets/images/turrets/combo-turret.png");
    comboTurretSelector->setPos(310, 10);
    connect(comboTurretSelector, &PopupSelectorItem::pressed, this, [=]() { emit turretSelected(model::TurretType::ComboTurret); });

    splitTurretSelector = new PopupSelectorItem(this, ":/assets/images/turrets/split-turret.png");
    splitTurretSelector->setPos(410, 10);
    connect(splitTurretSelector, &PopupSelectorItem::pressed, this, [=]() { emit turretSelected(model::TurretType::SplitTurret); });

    slowTimeTurretSelector = new PopupSelectorItem(this, ":/assets/images/turrets/slowtime-turret.png");
    slowTimeTurretSelector->setPos(510, 10);
    connect(slowTimeTurretSelector, &PopupSelectorItem::pressed, this, [=]() { emit turretSelected(model::TurretType::SlowTimeTurret); });
}

QRectF TurretSelector::boundingRect() const {
    return QRectF(0, 0, 600, 100);
}

void TurretSelector::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QPen pen;
    pen.setColor(Qt::black);
    pen.setWidth(5);

    painter->setPen(pen);
    painter->setBrush(QBrush(QColor::fromRgb(70, 70, 70)));
    painter->drawRect(0, 0, 600, 100);
}

void TurretSelector::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    Q_UNUSED(event);

    // To prevent clicks below
}

void TurretSelector::added(U_INT gameCredits) {
    setFocus();

    weakTurretSelector->setAvailability(gameCredits >= model::turretTypes.at(model::TurretType::WeakTurret).cost);
    mitraTurretSelector->setAvailability(gameCredits >= model::turretTypes.at(model::TurretType::MitraTurret).cost);
    granadeTurretSelector->setAvailability(gameCredits >= model::turretTypes.at(model::TurretType::GranadeTurret).cost);
    comboTurretSelector->setAvailability(gameCredits >= model::turretTypes.at(model::TurretType::ComboTurret).cost);
    splitTurretSelector->setAvailability(gameCredits >= model::turretTypes.at(model::TurretType::SplitTurret).cost);
    slowTimeTurretSelector->setAvailability(gameCredits >= model::turretTypes.at(model::TurretType::SlowTimeTurret).cost);
}

void TurretSelector::focusOutEvent(QFocusEvent *event) {
    Q_UNUSED(event);

    emit losedFocusSignal();
}

}  // namespace view
