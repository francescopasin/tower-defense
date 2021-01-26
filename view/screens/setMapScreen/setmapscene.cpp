#include "view/screens/setMapScreen/setmapscene.h"

#include <algorithm>

#include "view/hud/iconbutton.h"
#include "view/screens/setMapScreen/setmapgrid.h"

using std::vector;

namespace view {

SetMapScene::SetMapScene(){
    // Performance optimization
    setItemIndexMethod(QGraphicsScene::NoIndex);

    setSceneRect(0, 0, 1920, 1080);

    drawBackground();
    createHUD();

    auto grid = new SetMapGrid(QSize(96 * 16, 96 * 9));
    grid->setPos(0, 1080 - grid->boundingRect().height());
    addItem(grid);
}

void SetMapScene::drawBackground() {
    QBrush brush = QBrush(QColor::fromRgb(50, 50, 50));
    setBackgroundBrush(brush);
}

void SetMapScene::createHUD() {

}

}  // namespace view
