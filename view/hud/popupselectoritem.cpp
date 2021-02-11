#include "view/hud/popupselectoritem.h"

#include <QCursor>
#include <QPainter>
#include <QStyleOptionGraphicsItem>

namespace view {

PopupSelectorItem::PopupSelectorItem(QGraphicsItem *parent, const QString &imagePath, bool sendHoverEvents)
    : QGraphicsItem(parent), _imagePath(imagePath), isAvailable(true) {
    if (sendHoverEvents) {
        setAcceptHoverEvents(true);
    }

    updateCursor();
}

QRectF PopupSelectorItem::boundingRect() const {
    return QRectF(0, 0, 80, 80);
}

void PopupSelectorItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QPixmap pixmap = QPixmap(_imagePath);

    painter->setPen(Qt::NoPen);
    painter->drawPixmap(QRect(0, 0, 80, 80), pixmap);
}

void PopupSelectorItem::updateCursor() {
    if (isAvailable) {
        QPixmap pixmap = QPixmap(":/assets/images/pointers/pointer-interactive.png");
        setCursor(QCursor(pixmap.scaled(32, 32)));
        setOpacity(1);
    } else {
        QPixmap pixmap = QPixmap(":/assets/images/pointers/pointer-not-allowed.png");
        setCursor(QCursor(pixmap.scaled(32, 32)));
        setOpacity(0.5);
    }
}

void PopupSelectorItem::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    Q_UNUSED(event);

    if (isAvailable) {
        emit pressed();
    }
}

void PopupSelectorItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event) {
    Q_UNUSED(event);

    emit hoverEnter();
}

void PopupSelectorItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *event) {
    Q_UNUSED(event);

    emit hoverLeave();
}

void PopupSelectorItem::setAvailability(bool availability) {
    isAvailable = availability;
    updateCursor();
}

}  // namespace view
