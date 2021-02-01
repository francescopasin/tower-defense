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
    StandardButton* startButton = new StandardButton("START", 400);
    StandardButton* setMapButton = new StandardButton("SET MAP", 400);
    StandardButton* uploadMapButton = new StandardButton("UPLOAD MAP", 400);

    qreal size = startButton->boundingRect().width() + 10 + setMapButton->boundingRect().width() + 10 + uploadMapButton->boundingRect().width();

    startButton->setPos(
        1920 / 2 - size / 2,
        1080 / 2 - startButton->boundingRect().height() / 2);
    setMapButton->setPos(
        1920 / 2 - (size / 2) + startButton->boundingRect().width() + 10,
        1080 / 2 - setMapButton->boundingRect().height() / 2);
    uploadMapButton->setPos(
        1920 / 2 + size / 2 - uploadMapButton->boundingRect().width(),
        1080 / 2 - uploadMapButton->boundingRect().height() / 2);

    addItem(startButton);
    addItem(setMapButton);
    addItem(uploadMapButton);

    connect(startButton, &StandardButton::pressed, this, &InitialScreenScene::startButtonPressed);
    connect(setMapButton, &StandardButton::pressed, this, &InitialScreenScene::setMapButtonPressed);
    connect(uploadMapButton, &StandardButton::pressed, this, &InitialScreenScene::uploadMapButtonPressed);
}

}  // namespace view
