#ifndef HUD_INFOBOX_H_
#define HUD_INFOBOX_H_

#include <QGraphicsItem>

namespace view {

class InfoBox : public QGraphicsItem {
   private:
    QString _imagePath;
    QString _text;

   public:
    InfoBox(QString imagePath, QString text);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

}  // namespace view

#endif