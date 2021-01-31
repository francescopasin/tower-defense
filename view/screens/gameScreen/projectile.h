#ifndef GAMESCREEN_PROJECTILE_H_
#define GAMESCREEN_PROJECTILE_H_

#include <QGraphicsItem>

#define U_INT unsigned short int

namespace view {

class Projectile : public QGraphicsItem {
   private:
    qreal deltaX;
    qreal deltaY;

    U_INT currentStep;
    // TODO: globalize projectile speed to delay enemies damage animation and update
    U_INT speed = 5;

   public:
    Projectile(QGraphicsItem *parent, const QPointF &startingPos, const QPointF &endingPos);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    bool move();
};

}  // namespace view

#endif