#include "view/screens/setMapScreen/cellselector.h"

#include <QCursor>
#include <QPainter>

#include "view/screens/setMapScreen/cellselectoritem.h"

namespace view {

CellSelector::CellSelector() {
    setFlag(QGraphicsItem::ItemIsFocusable);

    QPixmap pixmap = QPixmap(":/assets/images/pointer.png");
    setCursor(QCursor(pixmap.scaled(32, 32)));

    CellSelectorItem *freeCell = new CellSelectorItem(this, SetMapCell::Type::Free);
    freeCell->setPos(10, 10);
    connect(freeCell, &CellSelectorItem::pressed, this, [=]() { emit cellSelected(SetMapCell::Type::Free); });

    CellSelectorItem *blockedCell = new CellSelectorItem(this, SetMapCell::Type::Blocked);
    blockedCell->setPos(110, 10);
    connect(blockedCell, &CellSelectorItem::pressed, this, [=]() { emit cellSelected(SetMapCell::Type::Blocked); });

    CellSelectorItem *startCell = new CellSelectorItem(this, SetMapCell::Type::Start);
    startCell->setPos(210, 10);
    connect(startCell, &CellSelectorItem::pressed, this, [=]() { emit cellSelected(SetMapCell::Type::Start); });

    CellSelectorItem *finishCell = new CellSelectorItem(this, SetMapCell::Type::Finish);
    finishCell->setPos(310, 10);
    connect(finishCell, &CellSelectorItem::pressed, this, [=]() { emit cellSelected(SetMapCell::Type::Finish); });

    CellSelectorItem *orizzCell = new CellSelectorItem(this, SetMapCell::Type::Orizz);
    orizzCell->setPos(410, 10);
    connect(orizzCell, &CellSelectorItem::pressed, this, [=]() { emit cellSelected(SetMapCell::Type::Orizz); });

    CellSelectorItem *vertCell = new CellSelectorItem(this, SetMapCell::Type::Vert);
    vertCell->setPos(10, 110);
    connect(vertCell, &CellSelectorItem::pressed, this, [=]() { emit cellSelected(SetMapCell::Type::Vert); });

    CellSelectorItem *sxupCell = new CellSelectorItem(this, SetMapCell::Type::SxUp);
    sxupCell->setPos(110, 110);
    connect(sxupCell, &CellSelectorItem::pressed, this, [=]() { emit cellSelected(SetMapCell::Type::SxUp); });

    CellSelectorItem *dxupCell = new CellSelectorItem(this, SetMapCell::Type::DxUp);
    dxupCell->setPos(210, 110);
    connect(dxupCell, &CellSelectorItem::pressed, this, [=]() { emit cellSelected(SetMapCell::Type::DxUp); });

    CellSelectorItem *sxdwCell = new CellSelectorItem(this, SetMapCell::Type::SxDw);
    sxdwCell->setPos(310, 110);
    connect(sxdwCell, &CellSelectorItem::pressed, this, [=]() { emit cellSelected(SetMapCell::Type::SxDw); });

    CellSelectorItem *dxdwCell = new CellSelectorItem(this, SetMapCell::Type::DxDw);
    dxdwCell->setPos(410, 110);
    connect(dxdwCell, &CellSelectorItem::pressed, this, [=]() { emit cellSelected(SetMapCell::Type::DxDw); });
}

QRectF CellSelector::boundingRect() const {
    return QRectF(0, 0, 500, 200);
}

void CellSelector::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QPen pen;
    pen.setColor(Qt::black);
    pen.setWidth(5);

    painter->setPen(pen);
    painter->setBrush(QBrush(QColor::fromRgb(70, 70, 70)));
    painter->drawRect(0, 0, 500, 200);
}

void CellSelector::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    // To prevent clicks below
}

void CellSelector::focusOutEvent(QFocusEvent *event) {
    emit losedFocusSignal();
}

}  // namespace view
