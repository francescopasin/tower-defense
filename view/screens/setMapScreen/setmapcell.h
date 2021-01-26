#ifndef VIEW_SETMAPCELL_H_
#define VIEW_SETMAPCELL_H_

#include <QGraphicsItem>

#include "view/screens/gameScreen/gridcelltype.h"

namespace view {

class SetMapCell : public QGraphicsItem {
   private:
    qreal _size;
    GridCellType _type;

   public:
    SetMapCell(QGraphicsItem *parent, qreal size, GridCellType type = GridCellType::Free);

    QRectF boundingRect() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

}  // namespace view

#endif