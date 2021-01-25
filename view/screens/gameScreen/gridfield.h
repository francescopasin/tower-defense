#ifndef VIEW_GRIDFIELD_H_
#define VIEW_GRIDFIELD_H_

#include <QGraphicsItem>
#include <vector>

#include "model/pathcell.h"
#include "model/position.h"
#include "view/screens/gameScreen/gridcell.h"
#include "view/screens/gameScreen/gridcelltype.h"

using std::vector;

namespace view {

class GridField : public QObject, public QGraphicsItem {
    Q_OBJECT

   private:
    QSize _size;
    vector<model::PathCell> _path;
    vector<model::Position> _blockedCells;
    vector<GridCell *> interactiveCells;

    void createGameGrid();

   public:
    GridField(const QSize &size, const vector<model::PathCell> &path, const vector<model::Position> blockedCells);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

   public slots:
    void selectCell(GridCell *cell);

   signals:
    void cellPressed(GridCellType cellType, const QPointF &coordinates);
};

}  // namespace view

#endif