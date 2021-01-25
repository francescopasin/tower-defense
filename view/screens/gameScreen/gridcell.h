#ifndef VIEW_GRIDCELL_H_
#define VIEW_GRIDCELL_H_

#include <QGraphicsItem>

#include "view/screens/gameScreen/gridcelltype.h"

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

class GridCell : public QObject, public QGraphicsItem {
    Q_OBJECT

   private:
    qreal _size;
    GridCellType _type;
    PathGridCellTile _tile;
    bool _selected;

   protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

   public:
    GridCell(QGraphicsItem *parent, qreal size, GridCellType type = GridCellType::Free, PathGridCellTile tile = PathGridCellTile::Horizontal);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    bool isSelected() const;
    void setSelected(bool selected);

    GridCellType getType() const;

   signals:
    void pressed(GridCell *cell);
};

}  // namespace view

#endif