#ifndef VIEW_TURRETSELECTOR_H_
#define VIEW_TURRETSELECTOR_H_

#include <QGraphicsItem>

#include "app/shortcuts.h"
#include "model/turrets/turrettype.h"
#include "view/screens/gameScreen/turretselectoritem.h"
namespace view {

class TurretSelector : public QObject, public QGraphicsItem {
    Q_OBJECT

   private:
    TurretSelectorItem *weakTurretSelector;
    TurretSelectorItem *mitraTurretSelector;
    TurretSelectorItem *granadeTurretSelector;
    TurretSelectorItem *comboTurretSelector;
    TurretSelectorItem *splitTurretSelector;
    TurretSelectorItem *slowTimeTurretSelector;

   protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void focusOutEvent(QFocusEvent *event) override;

   public:
    TurretSelector();

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    // Called when the item is shown, to recalculate which turrets can be added
    void added(U_INT gameCredits);

   signals:
    void turretSelected(model::TurretType turretType);
    void losedFocusSignal();
};

}  // namespace view

#endif