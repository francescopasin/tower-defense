#ifndef VIEW_TURRETSELECTORITEM_H_
#define VIEW_TURRETSELECTORITEM_H_

#include <QGraphicsItem>

#include "app/shortcuts.h"
#include "model/turrets/turrettype.h"

namespace view {

class TurretSelectorItem : public QObject, public QGraphicsItem {
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)

   private:
    model::TurretType _turretType;
    bool isAvailable;

   protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

   public:
    TurretSelectorItem(QGraphicsItem *parent, model::TurretType turretType);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void updateAvailability(U_INT gameCredits);

   signals:
    void pressed();
};

}  // namespace view

#endif
