#include "view/hud/standardbutton.h"

#include <QPainter>
#include <QStyleOptionGraphicsItem>

namespace view {

StandardButton::StandardButton(const QString &text, QGraphicsItem *parent) : QGraphicsItem(parent), _text(text) {
    setAcceptHoverEvents(true);
    //setFlag(QGraphicsItem::ItemIgnoresTransformations);

    QPixmap pixmap = QPixmap(":/assets/images/pointer-interactive.png");
    setCursor(QCursor(pixmap.scaled(32, 32)));
}

QRectF StandardButton::boundingRect() const {
    //QFont font;
    //font.fromString("Press Start 2P, -1, 30, 5, 50, 0, 0, 0, 0, 0");
    //QFontMetrics fontMetric(font);

    QFont font("Press Start 2P", 30);
    QFontMetrics fm(font);
    int pixelsWide = fm.horizontalAdvance(_text);

    return QRectF(0, 0, pixelsWide + 90, 128);  //TODO: Calculate width in abetter way
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

    QFontMetrics fontMetric(font);

    painter->drawPixmap(QRect(0, 0, fontMetric.horizontalAdvance(_text) + 90, 128), pixmap);

    painter->drawText(QRect(45, 45, fontMetric.horizontalAdvance(_text), 50), Qt::AlignCenter, _text);  // MAGIC NUMBERS
}

void StandardButton::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    Q_UNUSED(event);

    emit pressed();
}

}  // namespace view
