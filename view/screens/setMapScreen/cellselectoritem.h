#ifndef VIEW_CELLSELECTORITEM_H_
#define VIEW_CELLSELECTORITEM_H_

#include <QGraphicsItem>

#include "view/screens/setMapScreen/setmapcell.h"

namespace view {

class CellSelectorItem : public QObject, public QGraphicsItem {
    Q_OBJECT

   private:
    SetMapCell::Type _cellType;

   protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

   public:
    CellSelectorItem(QGraphicsItem *parent, SetMapCell::Type cellType);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

   signals:
    void pressed();
};

}  // namespace view

#endif