#include "view/screens/setMapScreen/setmapcell.h"

#include <QPainter>
#include <QStyleOptionGraphicsItem>

namespace view {

SetMapCell::SetMapCell(
    QGraphicsItem *parent,
    qreal size,
    GridCellType type)
    : QGraphicsItem(parent),
      _size(size),
      _type(type) {
    if (type == GridCellType::Free || type == GridCellType::Occupied) {
        setAcceptHoverEvents(true);

        QPixmap pixmap;
        if (type == GridCellType::Free) {
            pixmap = QPixmap(":/assets/images/pointer-turret-place.png");
        } else {
            pixmap = QPixmap(":/assets/images/pointer-turret-remove.png");
        }
        setCursor(QCursor(pixmap.scaled(32, 32)));
    }
}

QRectF SetMapCell::boundingRect() const {
    return QRectF(0, 0, _size, _size);
}

void SetMapCell::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(widget);

    QString imagePath;

    switch (_type) {
        case GridCellType::Free:
            imagePath = ":/assets/images/free-tile.png";

            if (option->state & QStyle::State_MouseOver) {
                imagePath = ":/assets/images/free-tile-pressed.png";
            }
            break;
        case GridCellType::Path:
            imagePath = ":/assets/images/horizontal-tile.png";
            break;
        case GridCellType::Blocked:
            imagePath = ":/assets/images/blocked-tile.png";
            break;
    }

    QPixmap pixmap = QPixmap(imagePath);
    painter->drawPixmap(QRect(0, 0, _size, _size), pixmap);
}

}  // namespace view
