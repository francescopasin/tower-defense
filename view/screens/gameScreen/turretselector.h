#ifndef VIEW_TURRETSELECTOR_H_
#define VIEW_TURRETSELECTOR_H_

#include <QGraphicsItem>

namespace view {

class TurretSelector : public QGraphicsItem {
   public:
    TurretSelector();

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

}  // namespace view

#endif