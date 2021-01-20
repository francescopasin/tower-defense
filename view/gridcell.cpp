#include "view/gridcell.h"

#include <QPainter>
#include <QStyleOptionGraphicsItem>

namespace view {

GridCell::GridCell(qreal size, GridCellType type, PathGridCellTile tile) : _size(size), _type(type), _tile(tile) {
    // TODO: understand why it doesn't work
    //setFlag(QGraphicsItem::ItemIgnoresTransformations);

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

QRectF GridCell::boundingRect() const {
    return QRectF(0, 0, _size, _size);
}

void GridCell::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
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
            switch (_tile) {
                case PathGridCellTile::Horizontal:
                default:
                    imagePath = ":/assets/images/horizontal-tile.png";
                    break;
                case PathGridCellTile::Vertical:
                    imagePath = ":/assets/images/vertical-tile.png";
                    break;
                case PathGridCellTile::TopRight:
                    imagePath = ":/assets/images/top-right-tile.png";
                    break;
                case PathGridCellTile::TopLeft:
                    imagePath = ":/assets/images/top-left-tile.png";
                    break;
                case PathGridCellTile::BottomRight:
                    imagePath = ":/assets/images/bottom-right-tile.png";
                    break;
                case PathGridCellTile::BottomLeft:
                    imagePath = ":/assets/images/bottom-left-tile.png";
                    break;
            }

            break;
        case GridCellType::PathStart:
            switch (_tile) {
                case PathGridCellTile::Left:
                default:
                    imagePath = ":/assets/images/left-start-tile.png";
                    break;
                case PathGridCellTile::Right:
                    imagePath = ":/assets/images/right-start-tile.png";
                    break;
                case PathGridCellTile::Top:
                    imagePath = ":/assets/images/top-start-tile.png";
                    break;
                case PathGridCellTile::Bottom:
                    imagePath = ":/assets/images/bottom-start-tile.png";
                    break;
            }
            break;
        case GridCellType::PathEnd:
            switch (_tile) {
                case PathGridCellTile::Left:
                default:
                    imagePath = ":/assets/images/left-end-tile.png";
                    break;
                case PathGridCellTile::Right:
                    imagePath = ":/assets/images/right-end-tile.png";
                    break;
                case PathGridCellTile::Top:
                    imagePath = ":/assets/images/top-end-tile.png";
                    break;
                case PathGridCellTile::Bottom:
                    imagePath = ":/assets/images/bottom-end-tile.png";
                    break;
            }
            break;
        case GridCellType::Blocked:
            imagePath = ":/assets/images/blocked-tile.png";
            break;
        case GridCellType::Occupied:
            //
            break;
    }

    QPixmap pixmap = QPixmap(imagePath);
    painter->drawPixmap(QRect(0, 0, _size, _size), pixmap);
}

}  // namespace view
