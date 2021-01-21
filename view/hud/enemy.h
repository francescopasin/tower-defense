#ifndef HUD_ENEMY_H_
#define HUD_ENEMY_H_

#include <QGraphicsItem>

namespace view {

class Enemy : public QGraphicsItem {
   public:
    Enemy();

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

}  // namespace view

#endif