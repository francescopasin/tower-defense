#ifndef VIEW_GRIDFIELD_H_
#define VIEW_GRIDFIELD_H_

#include <QGraphicsItem>
#include <vector>

#include "model/pathcell.h"
#include "model/position.h"

using std::vector;

namespace view {

class GridField : public QGraphicsItem {
   private:
    QSize _size;
    vector<model::PathCell> _path;
    vector<model::Position> _blockedCells;

    void createGameGrid();

   public:
    GridField(const QSize &size, const vector<model::PathCell> &path, const vector<model::Position> blockedCells);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

}  // namespace view

#endif