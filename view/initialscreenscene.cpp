#include "view/initialscreenscene.h"

namespace view {

InitialScreenScene::InitialScreenScene() {
    // Performance optimization
    setItemIndexMethod(QGraphicsScene::NoIndex);

    setSceneRect(0, 0, 1920, 1080);

    drawBackground();
    createHUD();
}

void InitialScreenScene::drawBackground() {
    QBrush brush = QBrush(QColor::fromRgb(50, 50, 50));
    setBackgroundBrush(brush);
}

void InitialScreenScene::createHUD() {
    // TODO

    // TODO: draw start button
}

}  // namespace view
