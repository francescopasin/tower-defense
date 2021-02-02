#include "view/screens/tutorialScreen/tutorialscene.h"

namespace view {

TutorialScene::TutorialScene() {
    // Performance optimization
    setItemIndexMethod(QGraphicsScene::NoIndex);

    setSceneRect(0, 0, 1920, 1080);

    drawBackground();
}

void TutorialScene::drawBackground() {
    QBrush brush = QBrush(QColor::fromRgb(50, 50, 50));
    setBackgroundBrush(brush);
}

}  // namespace view
