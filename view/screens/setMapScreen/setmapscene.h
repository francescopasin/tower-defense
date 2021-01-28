#ifndef VIEW_SETMAPSCENE_H_
#define VIEW_SETMAPSCENE_H_

#include <QGraphicsScene>
#include <vector>

using std::shared_ptr;
using std::vector;

#include "view/screens/setMapScreen/cellselector.h"
#include "view/screens/setMapScreen/setmapgrid.h"

#define SP shared_ptr

namespace view {

class SetMapScene : public QGraphicsScene {
    Q_OBJECT

   private:
    CellSelector* cellSelector;
    SetMapGrid* grid;

    void drawBackground();
    void createHUD();

   public:
    SetMapScene();

   public slots:
    void gridCellPressed(SetMapCell::Type cellType, const QPointF& coordinates);
    void closeCellSelector();
    void addCell(view::SetMapCell::Type cellType);
    void clearAll();

   signals:
    void saveButtonPressed(const vector<SetMapCell*>* cells);

    void cellPressed(SetMapCell::Type cellType, const QPointF& coordinates);
    void addCellSignal(SetMapCell* cell, view::SetMapCell::Type type);
};

}  // namespace view

#endif
