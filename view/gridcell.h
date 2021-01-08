#ifndef VIEW_GRIDCELL_H_
#define VIEW_GRIDCELL_H_

#include <QGraphicsItem>

namespace view {

class GridCell : public QGraphicsItem {
   private:
    qreal _size;
    bool _isPath;

   public:
    GridCell(qreal size, bool isPath = false);

    QRectF boundingRect() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

}  // namespace view

#endif