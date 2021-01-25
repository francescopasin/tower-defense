#ifndef VIEW_STANDARDBUTTON_H_
#define VIEW_STANDARDBUTTON_H_

#include <QGraphicsItem>

namespace view {

class StandardButton : public QObject, public QGraphicsItem {
    Q_OBJECT

   private:
    QString _text;

   protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

   public:
    StandardButton(const QString &text);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

   signals:
    void pressed();
};

}  // namespace view

#endif