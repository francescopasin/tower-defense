#include "view/hud/standardbutton.h"

#include <QPainter>
#include <QStyleOptionGraphicsItem>

namespace view {

StandardButton::StandardButton(const QString &text, int width, QGraphicsItem *parent) : QGraphicsItem(parent), _text(text), _width(width) {
    setAcceptHoverEvents(true);
    //setFlag(QGraphicsItem::ItemIgnoresTransformations);

    QPixmap pixmap = QPixmap(":/assets/images/pointer-interactive.png");
    QGraphicsItem::setCursor(QCursor(pixmap.scaled(32, 32)));
}

QRectF StandardButton::boundingRect() const {
    //QFont font;
    //font.fromString("Press Start 2P, -1, 30, 5, 50, 0, 0, 0, 0, 0");
    //QFontMetrics fontMetric(font);

    // QFont font("Press Start 2P", 30);
    // QFontMetrics fm(font);
    // int pixelsWide = fm.horizontalAdvance(_text);

    return QRectF(0, 0, _width, 128);  //TODO: Calculate width in abetter way
}

void StandardButton::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(widget);

    QPixmap pixmap;

    if (option->state & QStyle::State_MouseOver) {
        pixmap = QPixmap(":/assets/images/standard-button-pressed.png");
    } else {
        pixmap = QPixmap(":/assets/images/standard-button.png");
    }

    QFont font = painter->font();
    font.setPixelSize(30);
    font.setFamily("Press Start 2P");
    painter->setFont(font);

    QPen pen = QPen(QColor::fromRgb(255, 255, 255));
    painter->setPen(pen);

    // QFontMetrics fontMetric(font);

    // _width = fontMetric.horizontalAdvance(_text);

    painter->drawPixmap(QRect(0, 0, _width, 128), pixmap);

    painter->drawText(QRect(0, 45, _width, 50), Qt::AlignCenter, _text);
}

void StandardButton::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    Q_UNUSED(event);

    emit pressed();
}

}  // namespace view
