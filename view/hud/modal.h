#ifndef VIEW_MODAL_H_
#define VIEW_MODAL_H_

#include <QGraphicsItem>

namespace view {

class Modal : public QObject, public QGraphicsItem {
    Q_OBJECT

   private:
    bool _closeOnClick;

   protected:
    QSizeF size;

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void paintContent(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) = 0;

   public:
    Modal(qreal width, qreal height, bool closeOnClick = false);  // Pass QSize in constructor

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

   signals:
    void close();
};

}  // namespace view

#endif