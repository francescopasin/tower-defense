#ifndef VIEW_POPUPSELECTORITEM_H_
#define VIEW_POPUPSELECTORITEM_H_

#include <QGraphicsItem>

namespace view {

class PopupSelectorItem : public QObject, public QGraphicsItem {
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)

   private:
    QString _imagePath;
    bool isAvailable;

    void updateCursor();

   protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;

   public:
    PopupSelectorItem(QGraphicsItem *parent, const QString &imagePath);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void setAvailability(bool availability);

   signals:
    void pressed();
    void hover();
};

}  // namespace view

#endif
