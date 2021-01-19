#include "view/hud/infobox.h"

#include <QPainter>

namespace view {

InfoBox::InfoBox(QString imagePath, QString text) : _imagePath(imagePath), _text(text) {
    setFlag(QGraphicsItem::ItemIgnoresTransformations);
}

QRectF InfoBox::boundingRect() const {
    return QRectF(0, 0, 250, 50);
}

void InfoBox::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QPixmap pixmap = QPixmap(_imagePath);
    painter->drawPixmap(QRect(0, 0, 48, 48), pixmap);

    QFont font = painter->font();
    font.setPixelSize(30);
    font.setFamily("Press Start 2P");
    painter->setFont(font);

    QPen pen = QPen(QColor::fromRgb(180, 180, 180));
    painter->setPen(pen);

    painter->drawText(QRect(60, 5, 160, 50), Qt::AlignVCenter, _text);
}

}  // namespace view
