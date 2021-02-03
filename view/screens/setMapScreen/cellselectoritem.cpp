#include "view/screens/setMapScreen/cellselectoritem.h"

#include <QCursor>
#include <QPainter>
#include <QStyleOptionGraphicsItem>

namespace view {

CellSelectorItem::CellSelectorItem(
    QGraphicsItem *parent,
    SetMapCell::Type cellType)
    : QGraphicsItem(parent),
      _cellType(cellType) {
    QPixmap pixmap = QPixmap(":/assets/images/pointer-interactive.png");
    setCursor(QCursor(pixmap.scaled(32, 32)));
}

QRectF CellSelectorItem::boundingRect() const {
    return QRectF(0, 0, 80, 80);
}

void CellSelectorItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(widget);
    Q_UNUSED(option);


    QString imagePath;

    switch (_cellType) {
        case SetMapCell::Type::Free:
            imagePath = ":/assets/images/free-tile.png";
            break;
        case SetMapCell::Type::Start:
            imagePath = ":/assets/images/left-start-tile.png";
            break;
        case SetMapCell::Type::Finish:
            imagePath = ":/assets/images/right-end-tile.png";
            break;
        case SetMapCell::Type::Vert:
            imagePath = ":/assets/images/vertical-tile.png";
            break;
        case SetMapCell::Type::Orizz:
            imagePath = ":/assets/images/horizontal-tile.png";
            break;
        case SetMapCell::Type::SxUp:
            imagePath = ":/assets/images/top-left-tile.png";
            break;
        case SetMapCell::Type::DxUp:
            imagePath = ":/assets/images/top-right-tile.png";
            break;
        case SetMapCell::Type::SxDw:
            imagePath = ":/assets/images/bottom-left-tile.png";
            break;
        case SetMapCell::Type::DxDw:
            imagePath = ":/assets/images/bottom-right-tile.png";
            break;
        case SetMapCell::Type::Blocked:
            imagePath = ":/assets/images/blocked-tile.png";
            break;
    }

    QPixmap pixmap = QPixmap(imagePath);
    painter->drawPixmap(QRect(0, 0, 80, 80), pixmap);
}

void CellSelectorItem::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    Q_UNUSED(event);
    emit pressed();
}

}  // namespace view
