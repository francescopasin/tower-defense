#include "view/screens/setMapScreen/setmapscene.h"

#include <algorithm>

#include "view/hud/iconbutton.h"
#include "view/hud/standardbutton.h"
#include "view/screens/setMapScreen/setmapgrid.h"

using std::vector;

namespace view {

SetMapScene::SetMapScene() {
    // Performance optimization
    setItemIndexMethod(QGraphicsScene::NoIndex);

    setSceneRect(0, 0, 1920, 1080);

    drawBackground();
    createHUD();

    auto grid = new SetMapGrid(QSize(96 * 16, 96 * 9));
    grid->setPos((1920 - 96 * 16) / 2, 1080 - grid->boundingRect().height());
    addItem(grid);
}

void SetMapScene::drawBackground() {
    QBrush brush = QBrush(QColor::fromRgb(50, 50, 50));
    setBackgroundBrush(brush);
}

void SetMapScene::createHUD() {
    StandardButton* saveButton = new StandardButton("SAVE");
    StandardButton* clearButton = new StandardButton("CLEAR");

    saveButton->setPos(
        1920 / 2 - (saveButton->boundingRect().width() + 10 + clearButton->boundingRect().width()) / 2,
        30);

    clearButton->setPos(
        1920 / 2 - (saveButton->boundingRect().width() + 10 + clearButton->boundingRect().width()) / 2 + 10 + saveButton->boundingRect().width(),
        30);

    connect(saveButton, &StandardButton::pressed, this, &SetMapScene::saveButtonPressed);
    connect(clearButton, &StandardButton::pressed, this, &SetMapScene::clearButtonPressed);

    addItem(saveButton);
    addItem(clearButton);
}

}  // namespace view
