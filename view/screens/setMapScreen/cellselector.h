#ifndef VIEW_CELLSELECTOR_H_
#define VIEW_CELLSELECTOR_H_

#include <QGraphicsItem>

#include "view/hud/popupselectoritem.h"
#include "view/screens/gameScreen/gridcelltype.h"
// TODO: move enum to hud

namespace view {

class CellSelector : public QObject, public QGraphicsItem {
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)
   private:
    PopupSelectorItem *freeCell;

   protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void focusOutEvent(QFocusEvent *event) override;

   public:
    CellSelector();

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void setFreeCellAvailability(bool availability);

   signals:
    void cellSelected(GridCellType type);
    void losedFocusSignal();
};

}  // namespace view

#endif
