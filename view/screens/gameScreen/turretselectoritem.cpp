#include "view/screens/gameScreen/turretselectoritem.h"

#include <QCursor>
#include <QPainter>
#include <QStyleOptionGraphicsItem>

namespace view {

TurretSelectorItem::TurretSelectorItem(
    QGraphicsItem *parent,
    model::TurretType turretType)
    : QGraphicsItem(parent),
      _turretType(turretType),
      isAvailable(true) {
    QPixmap pixmap = QPixmap(":/assets/images/pointer-interactive.png");
    setCursor(QCursor(pixmap.scaled(32, 32)));

    // TODO: check credits to see if the turret can be added
}

QRectF TurretSelectorItem::boundingRect() const {
    return QRectF(0, 0, 80, 80);
}

void TurretSelectorItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(widget);

    if (isAvailable) {
        painter->setPen(Qt::NoPen);

        QPixmap pixmap = QPixmap(":/assets/images/pointer-interactive.png");
        setCursor(QCursor(pixmap.scaled(32, 32)));
    } else {
        // TODO: TEMP: find a better indicator
        QPen pen;
        pen.setColor(Qt::red);
        pen.setWidth(5);
        painter->setPen(pen);

        QPixmap pixmap = QPixmap(":/assets/images/pointer-not-allowed.png");
        setCursor(QCursor(pixmap.scaled(32, 32)));
    }

    QPixmap pixmap;

    switch (_turretType) {
        case model::TurretType::WeakTurret:
            pixmap = QPixmap(":/assets/images/turrets/weak-turret.png");
            break;
        case model::TurretType::MitraTurret:
            pixmap = QPixmap(":/assets/images/turrets/mitra-turret.png");
            break;
        case model::TurretType::GranadeTurret:
            pixmap = QPixmap(":/assets/images/turrets/granade-turret.png");
            break;
        case model::TurretType::ComboTurret:
            pixmap = QPixmap(":/assets/images/turrets/combo-turret.png");
            break;
        case model::TurretType::SplitTurret:
            pixmap = QPixmap(":/assets/images/turrets/split-turret.png");
            break;
        case model::TurretType::SlowTimeTurret:
            pixmap = QPixmap(":/assets/images/turrets/slowtime-turret.png");
            break;
    }

    painter->drawPixmap(QRect(0, 0, 80, 80), pixmap);
}

void TurretSelectorItem::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    Q_UNUSED(event);

    if (isAvailable) {
        emit pressed();
    }
}

void TurretSelectorItem::updateAvailability(U_INT gameCredits) {
    isAvailable = gameCredits >= model::turretTypes.at(_turretType).cost;
    // TODO: add not available cursor
}

}  // namespace view
