#include "view/hud/modal.h"

#include <QCursor>
#include <QGraphicsScene>
#include <QPainter>

namespace view {

Modal::Modal(qreal width, qreal height, bool closeOnClick) : _closeOnClick(closeOnClick) {
    size.setWidth(width);
    size.setHeight(height);

    setZValue(9999);

    QPixmap pixmap = QPixmap(":/assets/images/pointer.png");
    setCursor(QCursor(pixmap.scaled(32, 32)));
}

QRectF Modal::boundingRect() const {
    return QRectF(0, 0, size.width(), size.height());
}

void Modal::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QBrush brush(QColor::fromRgb(0, 0, 0, 200));

    painter->setPen(Qt::NoPen);
    painter->setBrush(brush);

    painter->drawRect(0, 0, size.width(), size.height());
}

void Modal::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (_closeOnClick) {
        emit close();
    }
}

}  // namespace view
