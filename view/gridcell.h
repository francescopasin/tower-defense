#ifndef VIEW_GRIDCELL_H_
#define VIEW_GRIDCELL_H_

#include <QGraphicsItem>

#include "view/gridcelltype.h"

namespace view {

class GridCell : public QGraphicsItem {
   private:
    qreal _size;
    GridCellType _type;

   public:
    GridCell(qreal size, GridCellType type = GridCellType::Free);

    QRectF boundingRect() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

}  // namespace view

#endif