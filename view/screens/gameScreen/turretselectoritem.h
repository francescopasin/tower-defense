#ifndef VIEW_TURRETSELECTORITEM_H_
#define VIEW_TURRETSELECTORITEM_H_

#include <QGraphicsItem>

#include "model/turrets/turrettype.h"

namespace view {

class TurretSelectorItem : public QObject, public QGraphicsItem {
    Q_OBJECT

   private:
    model::TurretType _turretType;

   public:
    TurretSelectorItem(QGraphicsItem *parent, model::TurretType turretType);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

}  // namespace view

#endif