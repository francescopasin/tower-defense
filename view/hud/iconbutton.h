#ifndef HUD_ICONBUTTON_H_
#define HUD_ICONBUTTON_H_

#include <QGraphicsItem>

namespace view {

class IconButton : public QGraphicsItem {
   private:
    QString _imagePath;
    QString _hoverImagePath;

   public:
    IconButton(QString imagePath, QString hoverImagePath);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

}  // namespace view

#endif