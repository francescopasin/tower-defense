#include "view/screens/gameScreen/turretinfospanel.h"

#include <QPainter>

namespace view {

TurretInfosPanel::TurretInfosPanel() {}

QRectF TurretInfosPanel::boundingRect() const {
    return QRectF(0, 0, 1920 - 96 * 16 - 10, 96 * 9);  // TODO: refactor all this numbers
}

void TurretInfosPanel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(Qt::NoPen);

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(QColor::fromRgb(70, 70, 70));

    painter->setBrush(brush);

    painter->drawRect(0, 0, 1920 - 96 * 16 - 10, 96 * 9);
}

}  // namespace view
