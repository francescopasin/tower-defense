#include "view/screens/gameScreen/turretselectoritem.h"

#include <QDebug>
#include <QPainter>

namespace view {

TurretSelectorItem::TurretSelectorItem(
    QGraphicsItem *parent,
    model::TurretType turretType)
    : QGraphicsItem(parent),
      _turretType(turretType) {
    setAcceptHoverEvents(true);
}

QRectF TurretSelectorItem::boundingRect() const {
    return QRectF(0, 0, 80, 80);
}

void TurretSelectorItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(Qt::NoPen);

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);

    switch (_turretType) {
        case model::TurretType::WeakTurret:
            brush.setColor(QColor::fromRgb(200, 100, 100));
            break;
        case model::TurretType::MitraTurret:
            brush.setColor(QColor::fromRgb(100, 200, 100));
            break;
        case model::TurretType::GranadeTurret:
            brush.setColor(QColor::fromRgb(100, 100, 200));
            break;
        case model::TurretType::ComboTurret:
            brush.setColor(QColor::fromRgb(50, 73, 210));
            break;
        case model::TurretType::SplitTurret:
            brush.setColor(QColor::fromRgb(120, 186, 20));
            break;
    }

    // TODO: add turrets images

    painter->setBrush(brush);
    painter->drawRect(0, 0, 80, 80);
}

}  // namespace view
