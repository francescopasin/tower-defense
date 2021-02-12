#ifndef VIEW_ICONBUTTON_H_
#define VIEW_ICONBUTTON_H_

#include <QGraphicsItem>

namespace view {

class IconButton : public QObject, public QGraphicsItem {
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)

   private:
    QString _imagePath;
    QString _hoverImagePath;

   protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

   public:
    IconButton(QString imagePath, QString hoverImagePath);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void changeImages(QString imagePath, QString hoverImagePath);

   signals:
    void pressed();
};

}  // namespace view

#endif
