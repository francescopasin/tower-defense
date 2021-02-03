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
    } else {
        // TODO: TEMP: find a better indicator
        QPen pen;
        pen.setColor(Qt::red);
        pen.setWidth(5);
        painter->setPen(pen);
    }

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

    // TODO: temp. For debugging
    QFont font = painter->font();
    font.setPixelSize(25);
    painter->setFont(font);
    painter->setPen(Qt::white);

    switch (_turretType) {
        case model::TurretType::WeakTurret:
            painter->drawText(QRect(0, 0, 80, 80), Qt::AlignCenter, "WEAK");
            break;
        case model::TurretType::MitraTurret:
            painter->drawText(QRect(0, 0, 80, 80), Qt::AlignCenter, "MITRA");
            break;
        case model::TurretType::GranadeTurret:
            painter->drawText(QRect(0, 0, 80, 80), Qt::AlignCenter, "GRAN");
            break;
        case model::TurretType::ComboTurret:
            painter->drawText(QRect(0, 0, 80, 80), Qt::AlignCenter, "COMBO");
            break;
        case model::TurretType::SplitTurret:
            painter->drawText(QRect(0, 0, 80, 80), Qt::AlignCenter, "SPLIT");
            break;
    }
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
