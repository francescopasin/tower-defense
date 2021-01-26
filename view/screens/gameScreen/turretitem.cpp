#include "view/screens/gameScreen/turretitem.h"

#include <QPainter>

#include "model/position.h"
#include "model/turrets/turrettype.h"

namespace view {

TurretItem::TurretItem(
    QGraphicsItem *parent,
    const model::SharedPtr<model::Turret> &turret,
    model::TurretType turretType,
    qreal cellSize)
    : QGraphicsItem(parent),
      turretData(turret),
      type(turretType),
      _cellSize(cellSize) {
    setPosition();
}

void TurretItem::setPosition() {
    model::Position position = turretData->getPosition();
    setPos(position.x * _cellSize + 5, position.y * _cellSize + 5);
}

QRectF TurretItem::boundingRect() const {
    return QRectF(0, 0, _cellSize - 10, _cellSize - 10);
}

void TurretItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(Qt::NoPen);

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);

    switch (type) {
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

    painter->setBrush(brush);

    painter->drawRect(0, 0, _cellSize - 10, _cellSize - 10);
}

void TurretItem::tick() {
    // TODO: attack

    //update();
}

}  // namespace view
