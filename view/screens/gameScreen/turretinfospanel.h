#ifndef VIEW_TURRETINFOSPANEL_H_
#define VIEW_TURRETINFOSPANEL_H_

#include <QGraphicsItem>

namespace view {

class TurretInfosPanel : public QGraphicsItem {
   public:
    TurretInfosPanel();

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

}  // namespace view

#endif