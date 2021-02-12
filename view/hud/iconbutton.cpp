#include "view/hud/iconbutton.h"

#include <QPainter>
#include <QStyleOptionGraphicsItem>

namespace view {

IconButton::IconButton(QString imagePath, QString hoverImagePath) : _imagePath(imagePath), _hoverImagePath(hoverImagePath) {
    setAcceptHoverEvents(true);
    ////setFlag(QGraphicsItem::ItemIgnoresTransformations);

    QPixmap pixmap = QPixmap(":/assets/images/pointers/pointer-interactive.png");
    setCursor(QCursor(pixmap.scaled(32, 32)));
}

QRectF IconButton::boundingRect() const {
    return QRectF(0, 0, 100, 100);
}

void IconButton::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(widget);

    if (option->state & QStyle::State_MouseOver) {
        // TODO: change with pixmap
        QImage image = QImage(_hoverImagePath);
        painter->drawImage(QRect(2, 2, 96, 96), image, QRect(0, 0, 16, 16));
    } else {
        QImage image = QImage(_imagePath);
        painter->drawImage(QRect(2, 2, 96, 96), image, QRect(0, 0, 16, 16));
    }
}

void IconButton::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    Q_UNUSED(event);

    emit pressed();
}

void IconButton::changeImages(QString imagePath, QString hoverImagePath) {
    _imagePath = imagePath;
    _hoverImagePath = hoverImagePath;
}

}  // namespace view
