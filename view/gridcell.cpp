#include "view/gridcell.h"

#include <QPainter>
#include <QStyleOptionGraphicsItem>

namespace view {

GridCell::GridCell(qreal size, bool isPath) : _size(size), _isPath(isPath) {
    if (!isPath) {
        setAcceptHoverEvents(true);
    }
}

QRectF GridCell::boundingRect() const {
    return QRectF(0, 0, _size, _size);
}

void GridCell::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(widget);

    QPen pen = QPen(_isPath ? QColor::fromRgb(80, 140, 80) : QColor::fromRgb(100, 100, 100));
    QBrush brush = QBrush(_isPath ? QColor::fromRgb(70, 130, 70) : QColor::fromRgb(70, 70, 70));

    if (option->state & QStyle::State_MouseOver) {
        pen.setWidth(2);
        pen.setColor(QColor::fromRgb(110, 110, 110));
        brush.setColor(QColor::fromRgb(90, 90, 90));
    }

    painter->setPen(pen);
    painter->setBrush(brush);

    painter->drawRect(0, 0, _size, _size);
}

}  // namespace view
