#include "view/screens/gameScreen/explosion.h"

#include <QPainter>

namespace view {

Explosion::Explosion() : spriteAnimationSpeed(1), currentSpriteFrame(0) {
    for (U_INT i = 1; i <= 14; i++) {
        sprites.push_back(QPixmap(QString(":/assets/images/explosion/explosion%1.png").arg(i)));
    }
}

QRectF Explosion::boundingRect() const {
    return QRectF(0, 0, 64, 64);
}

void Explosion::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->drawPixmap(QRect(0, 0, 64, 64), sprites[currentSpriteFrame]);
}

bool Explosion::tick() {
    if (spriteAnimationSpeed == 0) {
        currentSpriteFrame++;
        if (currentSpriteFrame == 14) {
            // return true if finished
            return true;
        }
        spriteAnimationSpeed = 1;
    } else {
        spriteAnimationSpeed--;
    }

    return false;
}

}  // namespace view
