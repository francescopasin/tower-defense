#include "view/gridcell.h"

#include <QPainter>
#include <QStyleOptionGraphicsItem>

namespace view {

GridCell::GridCell(qreal size, GridCellType type) : _size(size), _type(type) {
    if (type == GridCellType::Free || type == GridCellType::Occupied) {
        setAcceptHoverEvents(true);
        setCursor(Qt::PointingHandCursor);
    }
}

QRectF GridCell::boundingRect() const {
    return QRectF(0, 0, _size, _size);
}

void GridCell::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(widget);

    QPen pen = QPen();
    QBrush brush = QBrush();
    brush.setStyle(Qt::SolidPattern);

    switch (_type) {
        case GridCellType::Free:
            pen.setColor(QColor::fromRgb(100, 100, 100));
            brush.setColor(QColor::fromRgb(70, 70, 70));
            break;
        case GridCellType::Path:
            pen.setColor(QColor::fromRgb(80, 140, 80));
            brush.setColor(QColor::fromRgb(70, 130, 70));
            break;
        case GridCellType::PathStart:
            pen.setColor(QColor::fromRgb(130, 190, 130));
            brush.setColor(QColor::fromRgb(120, 180, 120));
            break;
        case GridCellType::PathEnd:
            pen.setColor(QColor::fromRgb(30, 90, 30));
            brush.setColor(QColor::fromRgb(20, 80, 20));
            break;
        case GridCellType::Blocked:
            pen.setColor(QColor::fromRgb(110, 80, 80));
            brush.setColor(QColor::fromRgb(100, 70, 70));
            break;
        case GridCellType::Occupied:
            pen.setColor(QColor::fromRgb(50, 50, 50));
            brush.setColor(QColor::fromRgb(20, 20, 20));
            break;
    }

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
