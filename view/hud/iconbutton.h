#ifndef HUD_ICONBUTTON_H_
#define HUD_ICONBUTTON_H_

#include <QGraphicsItem>

namespace view {

class IconButton : public QObject, public QGraphicsItem {
    Q_OBJECT

   private:
    QString _imagePath;
    QString _hoverImagePath;

   protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

   public:
    IconButton(QString imagePath, QString hoverImagePath);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

   signals:
    void pressed();
};

}  // namespace view

#endif