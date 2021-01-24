#include "view/screens/initialScreen/initialscreenscene.h"

#include "view/hud/standardbutton.h"

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
    StandardButton* startButton = new StandardButton("START");
    startButton->setPos(
        1920 / 2 - startButton->boundingRect().width() / 2,
        1080 / 2 - startButton->boundingRect().height() / 2);
    addItem(startButton);
    connect(startButton, &StandardButton::pressed, this, &InitialScreenScene::startButtonPressed);
}

}  // namespace view
