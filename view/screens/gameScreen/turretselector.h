#ifndef VIEW_TURRETSELECTOR_H_
#define VIEW_TURRETSELECTOR_H_

#include <QGraphicsItem>

#include "model/turrets/turrettype.h"

namespace view {

class TurretSelector : public QObject, public QGraphicsItem {
    Q_OBJECT

   protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void focusOutEvent(QFocusEvent *event) override;

   public:
    TurretSelector();

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

   signals:
    void turretSelected(model::TurretType turretType);
    void losedFocusSignal();
};

}  // namespace view

#endif