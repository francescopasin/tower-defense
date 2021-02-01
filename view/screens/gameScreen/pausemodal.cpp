#include "view/screens/gameScreen/pausemodal.h"

#include <QPainter>

#include "view/hud/standardbutton.h"

namespace view {

PauseModal::PauseModal(qreal width, qreal height) : Modal(width, height) {
    // Add external content

    StandardButton *resumeButton = new StandardButton("RESUME", 300, this);
    resumeButton->setPos(
        size.width() / 2 - resumeButton->boundingRect().width() / 2,
        size.height() / 2 - resumeButton->boundingRect().height() / 2);
    connect(resumeButton, &StandardButton::pressed, this, &Modal::close);

    StandardButton *menuButton = new StandardButton("MENU", 300, this);
    menuButton->setPos(
        size.width() / 2 - menuButton->boundingRect().width() / 2,
        size.height() / 2 - menuButton->boundingRect().height() / 2 + 200);
    connect(menuButton, &StandardButton::pressed, this, &PauseModal::returnToMenu);

    // TODO: add sound and music buttons

    // TODO: fix buttons transforms
}

void PauseModal::paintContent(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QFont font = painter->font();
    font.setPixelSize(40);
    font.setFamily("Press Start 2P");
    painter->setFont(font);
    painter->setPen(Qt::white);

    painter->drawText(QRectF(size.width() / 2 - 150, size.height() / 2 - 200, 300, 100), Qt::AlignCenter, "PAUSED");
}

}  // namespace view
