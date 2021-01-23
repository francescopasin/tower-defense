#ifndef VIEW_GRIDCELL_H_
#define VIEW_GRIDCELL_H_

#include <QGraphicsItem>

#include "view/gridcelltype.h"

namespace view {

enum class PathGridCellTile {
    Horizontal,
    Vertical,
    TopRight,
    TopLeft,
    BottomRight,
    BottomLeft,
    Top,
    Right,
    Left,
    Bottom
};

class GridCell : public QGraphicsItem {
   private:
    qreal _size;
    GridCellType _type;
    PathGridCellTile _tile;

   public:
    GridCell(QGraphicsItem *parent, qreal size, GridCellType type = GridCellType::Free, PathGridCellTile tile = PathGridCellTile::Horizontal);

    QRectF boundingRect() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

}  // namespace view

#endif