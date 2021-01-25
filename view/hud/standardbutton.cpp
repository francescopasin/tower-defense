#include "view/hud/standardbutton.h"

#include <QPainter>
#include <QStyleOptionGraphicsItem>

namespace view {

StandardButton::StandardButton(const QString &text) : _text(text) {
    setAcceptHoverEvents(true);
    setFlag(QGraphicsItem::ItemIgnoresTransformations);

    QPixmap pixmap = QPixmap(":/assets/images/pointer-interactive.png");
    setCursor(QCursor(pixmap.scaled(32, 32)));
}

QRectF StandardButton::boundingRect() const {
    return QRectF(0, 0, 256, 128);
}

void StandardButton::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(widget);

    QPixmap pixmap;

    if (option->state & QStyle::State_MouseOver) {
        pixmap = QPixmap(":/assets/images/standard-button-pressed.png");
    } else {
        pixmap = QPixmap(":/assets/images/standard-button.png");
    }

    painter->drawPixmap(QRect(0, 0, 256, 128), pixmap);

    QFont font = painter->font();
    font.setPixelSize(30);
    font.setFamily("Press Start 2P");
    painter->setFont(font);

    QPen pen = QPen(QColor::fromRgb(255, 255, 255));
    painter->setPen(pen);

    painter->drawText(QRect(0, 45, 256, 50), Qt::AlignCenter, _text);  // MAGIC NUMBERS
}

void StandardButton::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    Q_UNUSED(event);

    emit pressed();
}

}  // namespace view
