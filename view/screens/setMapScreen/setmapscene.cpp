#include "view/screens/setMapScreen/setmapscene.h"

#include <algorithm>

#include "view/hud/iconbutton.h"
#include "view/hud/standardbutton.h"
#include "view/screens/setMapScreen/cellselector.h"
#include "view/screens/setMapScreen/setmapgrid.h"

using std::vector;

namespace view {

SetMapScene::SetMapScene() {
    // Performance optimization
    setItemIndexMethod(QGraphicsScene::NoIndex);

    setSceneRect(0, 0, 1920, 1080);

    drawBackground();
    createHUD();

    grid = new SetMapGrid(QSize(96 * 16, 96 * 9));
    grid->setPos((1920 - 96 * 16) / 2, 1080 - grid->boundingRect().height());
    addItem(grid);
    connect(grid, &SetMapGrid::cellPressed, this, &SetMapScene::gridCellPressed);

    cellSelector = new CellSelector();
    connect(cellSelector, &CellSelector::losedFocusSignal, this, &SetMapScene::closeCellSelector);
    connect(cellSelector, &CellSelector::cellSelected, this, &SetMapScene::addCell);

    //connect(this, &SetMapScene::addCellSignal, grid, &SetMapGrid::addCell);
}

void SetMapScene::drawBackground() {
    QBrush brush = QBrush(QColor::fromRgb(50, 50, 50));
    setBackgroundBrush(brush);
}

void SetMapScene::createHUD() {
    StandardButton* saveButton = new StandardButton("SAVE");
    StandardButton* clearButton = new StandardButton("CLEAR");
    StandardButton* backButton = new StandardButton("BACK");

    saveButton->setPos(
        1920 / 2 - (saveButton->boundingRect().width() + 10 + clearButton->boundingRect().width()) / 2,
        30);

    clearButton->setPos(
        1920 / 2 - (saveButton->boundingRect().width() + 10 + clearButton->boundingRect().width()) / 2 + 10 + saveButton->boundingRect().width(),
        30);

    backButton->setPos(5, 5);

    connect(saveButton, &StandardButton::pressed, this, [=]() { emit saveButtonPressed(grid->getCells()); });
    connect(clearButton, &StandardButton::pressed, this, &SetMapScene::clearAll);
    connect(backButton, &StandardButton::pressed, this, &SetMapScene::backButtonPressed);

    addItem(saveButton);
    addItem(clearButton);
    addItem(backButton);
}

void SetMapScene::gridCellPressed(SetMapCell::Type cellType, const QPointF& coordinates) {
    cellSelector->setPos(
        qMax(coordinates.x() + 48 - cellSelector->boundingRect().width() / 2 + (1920 - 96 * 16) / 2, 0.0),
        coordinates.y() - cellSelector->boundingRect().height() + 1080 - grid->boundingRect().height());  // TODO: temp

    addItem(cellSelector);
    cellSelector->setFocus();
}

void SetMapScene::closeCellSelector() {
    removeItem(cellSelector);
    grid->selectCell(nullptr);
    grid->reDrawPath();
}

void SetMapScene::clearAll() {
    removeItem(cellSelector);
    grid->selectCell(nullptr);
    grid->clearAll();
}

void SetMapScene::addCell(view::SetMapCell::Type type) {
    // Get selected cell position
    auto pos = grid->getSelectedCellPosition();

    grid->addCell(pos, type);
    removeItem(cellSelector);
    grid->selectCell(nullptr);
}

}  // namespace view
