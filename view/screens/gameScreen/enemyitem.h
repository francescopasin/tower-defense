#ifndef VIEW_ENEMYITEM_H_
#define VIEW_ENEMYITEM_H_

#include <QGraphicsItem>

#include "app/shortcuts.h"
#include "model/enemy.h"

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
    bool isDead() const;

    bool hasEnemyData(const SP<model::Enemy> &enemy) const;
};

}  // namespace view

#endif