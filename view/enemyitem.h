#ifndef HUD_ENEMY_H_
#define HUD_ENEMY_H_

#include <QGraphicsItem>
#include <memory>

#include "model/enemy.h"

using std::shared_ptr;

#define SP shared_ptr

namespace view {

class EnemyItem : public QGraphicsItem {
   private:
    SP<model::Enemy> enemyData;
    qreal _cellSize;

    void setPosition();

   public:
    EnemyItem(QGraphicsItem *parent, const SP<model::Enemy> &enemy, qreal cellSize);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void tick();
};

}  // namespace view

#endif