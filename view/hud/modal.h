#ifndef VIEW_MODAL_H_
#define VIEW_MODAL_H_

#include <QGraphicsItem>

namespace view {

class Modal : public QObject, public QGraphicsItem {
    Q_OBJECT

   private:
    QSizeF size;
    bool _closeOnClick;

   protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

   public:
    Modal(qreal width, qreal height, bool closeOnClick = false);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

   signals:
    void close();
};

}  // namespace view

#endif