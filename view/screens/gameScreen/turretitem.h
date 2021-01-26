#ifndef VIEW_TURRETITEM_H_
#define VIEW_TURRETITEM_H_

#include <QGraphicsItem>

#include "model/sharedptr.h"
#include "model/turrets/turret.h"
#include "model/turrets/turrettype.h"

namespace view {

class TurretItem : public QGraphicsItem {
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

    void tick();
};

}  // namespace view

#endif