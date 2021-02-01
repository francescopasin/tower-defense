#include "view/hud/errormodal.h"

#include <QPainter>

#include "view/hud/standardbutton.h"

namespace view {

ErrorModal::ErrorModal(const QString &text, qreal width, qreal height) : _text(text), Modal(width, height, true) {
    // Add external content

    // StandardButton *resumeButton = new StandardButton("RESUME", 300, this);
    // resumeButton->setPos(
    //     size.width() / 2 - resumeButton->boundingRect().width() / 2,
    //     size.height() / 2 - resumeButton->boundingRect().height() / 2);
    // connect(resumeButton, &StandardButton::pressed, this, &Modal::close);
}

void ErrorModal::paintContent(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QPainter *p = painter;
    p->setRenderHint(QPainter::Antialiasing);

    QFont font = painter->font();
    font.setPixelSize(20);
    font.setFamily("Press Start 2P");
    font.setBold(true);
    QPen pen(Qt::red, 8);
    p->setPen(pen);
    painter->setFont(font);

    int height = 500;
    int width = 1300;

    QFontMetrics fontMetric(font);

    width = qMax(300, fontMetric.horizontalAdvance(_text));
    height = 15 + 100 + 30 + fontMetric.height() + 15;

    QString text = _text;

    if (width + 80 > 1300) {  // divide stringa in 2
        int s = _text.split(" ").size() / 2;
        QStringList list = _text.split(" ");
        list[s] += "\n";
        text = list.join(" ");
        list = text.split("\n");
        width = qMax(fontMetric.horizontalAdvance(list[0]), fontMetric.horizontalAdvance(list[1]));
        height += fontMetric.height();
    }

    painter->setBrush(Qt::black);
    painter->drawRoundedRect(QRectF((size.width() / 2) - (width / 2 + 40), (size.height() / 2) - (height / 2), width + 80, height), 10, 10);
    painter->setBrush(Qt::transparent);

    // p->fillPath(path, Qt::black);
    // p->drawPath(path);

    pen.setColor(Qt::white);
    painter->setPen(pen);
    painter->drawText(QRectF(size.width() / 2 - (width / 2), size.height() / 2 - (height / 2) + 45, width, height), Qt::AlignCenter, text);

    font.setPixelSize(50);
    painter->setFont(font);

    painter->drawText(QRectF(size.width() / 2 - 150, size.height() / 2 - (height / 2) + 15, 300, 100), Qt::AlignCenter, "ERROR");
}

}  // namespace view
