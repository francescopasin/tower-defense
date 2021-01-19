#ifndef HUD_TURRETSELECTORITEM_H_
#define HUD_TURRETSELECTORITEM_H_

#include <QGraphicsItem>

namespace view {

class TurretSelectorItem : public QGraphicsItem {
   public:
    TurretSelectorItem(QGraphicsItem *parent);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

}  // namespace view

#endif