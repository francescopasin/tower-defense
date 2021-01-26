#include "setmapgrid.h"

namespace view {

SetMapGrid::SetMapGrid(const QSize &size) : _size(size) {
    setFlag(ItemHasNoContents);
    createSetMapGrid();
}

void SetMapGrid::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);
    Q_UNUSED(painter);
}

QRectF SetMapGrid::boundingRect() const {
    return QRectF(0, 0, _size.width(), _size.height());
}

void SetMapGrid::createSetMapGrid() {
    qreal size = _size.height() / 9;

    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 9; j++) {
            SetMapCell *cell = new SetMapCell(this, size, GridCellType::Free);
            cell->setPos(i * size, j * size);
        }
    }
}

}  // namespace view
