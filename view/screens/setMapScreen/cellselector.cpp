#include "view/screens/setMapScreen/cellselector.h"

#include <QCursor>
#include <QPainter>

namespace view {

CellSelector::CellSelector() {
    setFlag(QGraphicsItem::ItemIsFocusable);

    QPixmap pixmap = QPixmap(":/assets/images/pointers/pointer.png");
    setCursor(QCursor(pixmap.scaled(32, 32)));

    freeCell = new PopupSelectorItem(this, ":/assets/images/tiles/general-path-tile.png");
    freeCell->setPos(10, 10);
    connect(freeCell, &PopupSelectorItem::pressed, this, [=]() { emit cellSelected(GridCellType::Path); });

    PopupSelectorItem *blockedCell = new PopupSelectorItem(this, ":/assets/images/tiles/blocked-tile.png");
    blockedCell->setPos(110, 10);
    connect(blockedCell, &PopupSelectorItem::pressed, this, [=]() { emit cellSelected(GridCellType::Blocked); });
}

QRectF CellSelector::boundingRect() const {
    return QRectF(0, 0, 200, 200);
}

void CellSelector::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QPen pen;
    pen.setColor(Qt::black);
    pen.setWidth(5);

    painter->setPen(pen);
    painter->setBrush(QBrush(QColor::fromRgb(70, 70, 70)));
    painter->drawRect(0, 0, 200, 200);
}

void CellSelector::setFreeCellAvailability(bool availability) {
    freeCell->setAvailability(availability);
}

void CellSelector::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    Q_UNUSED(event);

    // To prevent clicks below
}

void CellSelector::focusOutEvent(QFocusEvent *event) {
    Q_UNUSED(event);
    emit losedFocusSignal();
}

}  // namespace view
