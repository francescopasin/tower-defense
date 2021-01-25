#include "view/screens/gameScreen/turretselectoritem.h"

#include <QCursor>
#include <QPainter>
#include <QStyleOptionGraphicsItem>

namespace view {

TurretSelectorItem::TurretSelectorItem(
    QGraphicsItem *parent,
    model::TurretType turretType)
    : QGraphicsItem(parent),
      _turretType(turretType) {
    QPixmap pixmap = QPixmap(":/assets/images/pointer-interactive.png");
    setCursor(QCursor(pixmap.scaled(32, 32)));
}

QRectF TurretSelectorItem::boundingRect() const {
    return QRectF(0, 0, 80, 80);
}

void TurretSelectorItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(widget);

    painter->setPen(Qt::NoPen);

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);

    if (option->state & QStyle::State_MouseOver) {
        switch (_turretType) {
            case model::TurretType::WeakTurret:
                brush.setColor(QColor::fromRgb(240, 140, 140));
                break;
            case model::TurretType::MitraTurret:
                brush.setColor(QColor::fromRgb(140, 240, 140));
                break;
            case model::TurretType::GranadeTurret:
                brush.setColor(QColor::fromRgb(140, 140, 240));
                break;
            case model::TurretType::ComboTurret:
                brush.setColor(QColor::fromRgb(90, 113, 250));
                break;
            case model::TurretType::SplitTurret:
                brush.setColor(QColor::fromRgb(160, 226, 60));
                break;
        }
    } else {
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
    }

    // TODO: add turrets images

    painter->setBrush(brush);
    painter->drawRect(0, 0, 80, 80);
}

void TurretSelectorItem::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    Q_UNUSED(event);

    emit pressed();
}

}  // namespace view
