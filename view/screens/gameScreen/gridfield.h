#ifndef VIEW_GRIDFIELD_H_
#define VIEW_GRIDFIELD_H_

#include <QGraphicsItem>
#include <vector>

#include "model/pathcell.h"
#include "model/position.h"
#include "model/sharedptr.h"
#include "model/turrets/turret.h"
#include "model/turrets/turrettype.h"
#include "view/screens/gameScreen/gridcell.h"
#include "view/screens/gameScreen/gridcelltype.h"
#include "view/screens/gameScreen/turretitem.h"

using std::vector;

namespace view {

class GridField : public QObject, public QGraphicsItem {
    Q_OBJECT

   private:
    QSize _size;
    const vector<model::PathCell> &_path;
    const vector<model::Position> &_blockedCells;
    vector<GridCell *> interactiveCells;
    vector<TurretItem *> turrets;

    void createGameGrid();

   public:
    GridField(const QSize &size, const vector<model::PathCell> &path, const vector<model::Position> &blockedCells);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    model::Position getSelectedCellPosition() const;

    void addTurretItem(const model::SharedPtr<model::Turret> &turret, model::TurretType turretType);

   public slots:
    void selectCell(GridCell *cell);

   signals:
    void cellPressed(GridCellType cellType, model::Position cellPosition);
};

}  // namespace view

#endif