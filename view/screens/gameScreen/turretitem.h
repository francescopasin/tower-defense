#ifndef VIEW_TURRETITEM_H_
#define VIEW_TURRETITEM_H_

#include <QGraphicsItem>
#include <vector>

#include "model/enemy.h"
#include "model/position.h"
#include "model/sharedptr.h"
#include "model/turrets/turret.h"
#include "model/turrets/turrettype.h"
#include "view/screens/gameScreen/enemyitem.h"

using std::vector;

namespace view {

class TurretItem : public QObject, public QGraphicsItem {
    Q_OBJECT

   private:
    model::SharedPtr<model::Turret> turretData;
    model::TurretType type;
    qreal _cellSize;

    void setPosition();

   public:
    TurretItem(
        QGraphicsItem *parent,
        const model::SharedPtr<model::Turret> &turret,
        model::TurretType turretType,
        qreal cellSize);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    model::Position getGridPosition() const;
    void attack(const vector<EnemyItem *> &enemies);

    bool hasTurretData(const model::SharedPtr<model::Turret> &turret) const;

   signals:
    void spawnProjectile(const QPointF &startingPos, const QPointF &endingPos);
};

}  // namespace view

#endif