#ifndef SETMAPGRID_H
#define SETMAPGRID_H

#include <QGraphicsItem>
#include <vector>

#include "view/screens/setMapScreen/setmapcell.h"

namespace view {

class SetMapGrid : public QGraphicsItem {
   private:
    QSize _size;
    void createSetMapGrid();

   public:
    SetMapGrid(const QSize &size);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

};  // namespace view

#endif  // SETMAPGRID_H
