#include "view/gamescene.h"

#include <QDebug>
#include <QGraphicsRectItem>
#include <vector>

#include "view/gridcell.h"
#include "view/hud/iconbutton.h"
#include "view/hud/infobox.h"
#include "view/hud/turretselector.h"

using std::vector;

namespace view {

GameScene::GameScene(const SP<const model::GameModel>& model) : _model(model) {
    // Performance optimization
    setItemIndexMethod(QGraphicsScene::NoIndex);

    setSceneRect(0, 0, 1920, 1080);

    drawBackground();
    createGameGrid();
    createHUD();
}

void GameScene::drawBackground() {
    QBrush brush = QBrush(QColor::fromRgb(50, 50, 50));
    setBackgroundBrush(brush);
}

void GameScene::createGameGrid() {
    vector<model::PathCell> path = _model->getMap();
    vector<model::Position> blockedCells = _model->getBlockedCellsMap();

    qreal size = 96;

    // Path Cells
    // ========================================================================
    for (auto i = path.begin(); i != path.end(); i++) {
        GridCell* cell;

        if (i == path.begin()) {
            // First cell
            PathGridCellTile tile;

            switch (i->to) {
                case model::Direction::Left:
                    tile = PathGridCellTile::Right;
                    break;
                case model::Direction::Up:
                    tile = PathGridCellTile::Bottom;
                    break;
                case model::Direction::Right:
                    tile = PathGridCellTile::Left;
                    break;
                case model::Direction::Down:
                    tile = PathGridCellTile::Top;
                    break;
            }

            cell = new GridCell(size, GridCellType::PathStart, tile);
        } else if (i == path.end() - 1) {
            // Last cell
            PathGridCellTile tile;

            switch (i->from) {
                case model::Direction::Left:
                    tile = PathGridCellTile::Right;
                    break;
                case model::Direction::Up:
                    tile = PathGridCellTile::Bottom;
                    break;
                case model::Direction::Right:
                    tile = PathGridCellTile::Left;
                    break;
                case model::Direction::Down:
                    tile = PathGridCellTile::Top;
                    break;
            }

            cell = new GridCell(size, GridCellType::PathEnd, tile);
        } else {
            // Medium cell
            PathGridCellTile tile;

            switch (i->from) {
                case model::Direction::Left:
                    switch (i->to) {
                        case model::Direction::Up:
                            tile = PathGridCellTile::TopLeft;
                            break;
                        case model::Direction::Right:
                            tile = PathGridCellTile::Horizontal;
                            break;
                        case model::Direction::Down:
                            tile = PathGridCellTile::BottomLeft;
                            break;
                    }
                    break;
                case model::Direction::Up:
                    switch (i->to) {
                        case model::Direction::Left:
                            tile = PathGridCellTile::TopLeft;
                            break;
                        case model::Direction::Right:
                            tile = PathGridCellTile::TopRight;
                            break;
                        case model::Direction::Down:
                            tile = PathGridCellTile::Vertical;
                            break;
                    }
                    break;
                case model::Direction::Right:
                    switch (i->to) {
                        case model::Direction::Left:
                            tile = PathGridCellTile::Horizontal;
                            break;
                        case model::Direction::Up:
                            tile = PathGridCellTile::TopRight;
                            break;
                        case model::Direction::Down:
                            tile = PathGridCellTile::BottomRight;
                            break;
                    }
                    break;
                case model::Direction::Down:
                    switch (i->to) {
                        case model::Direction::Left:
                            tile = PathGridCellTile::BottomLeft;
                            break;
                        case model::Direction::Up:
                            tile = PathGridCellTile::Vertical;
                            break;
                        case model::Direction::Right:
                            tile = PathGridCellTile::BottomRight;
                            break;
                    }
                    break;
            }

            cell = new GridCell(size, GridCellType::Path, tile);
        }

        cell->setPos(i->x * size, i->y * size + (1080 - size * 9));
        addItem(cell);
    }

    // Blocked Cells
    // ========================================================================
    for (auto i = blockedCells.begin(); i != blockedCells.end(); i++) {
        GridCell* cell = new GridCell(size, GridCellType::Blocked);
        cell->setPos(i->x * size, i->y * size + (1080 - size * 9));
        addItem(cell);
    }

    // Free Cells
    // ========================================================================
    bool isFree = true;

    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 9; j++) {
            isFree = true;

            for (auto pathCell : path) {
                if (pathCell.x == i && pathCell.y == j) {
                    isFree = false;
                    break;
                }
            }

            for (auto blockedCell : blockedCells) {
                if (blockedCell.x == i && blockedCell.y == j) {
                    isFree = false;
                    break;
                }
            }

            if (isFree) {
                GridCell* cell = new GridCell(size, GridCellType::Free);
                cell->setPos(i * size, j * size + (1080 - size * 9));
                addItem(cell);
            }
        }
    }
}

void GameScene::createHUD() {
    // TODO: get info from model
    InfoBox* infoBox = new InfoBox(":/assets/images/coin.png", "10");
    infoBox->setPos(10, 15);
    addItem(infoBox);

    InfoBox* infoBox2 = new InfoBox(":/assets/images/heart.png", "90%");
    infoBox2->setPos(10, 75);
    addItem(infoBox2);

    IconButton* playPauseButton = new IconButton(":/assets/images/play-button-idle.png", ":/assets/images/play-button-pressed.png");
    playPauseButton->setPos(1400, 25);
    addItem(playPauseButton);
    connect(playPauseButton, &IconButton::pressed, this, &GameScene::playPauseButtonPressed);

    IconButton* fastForwardButton = new IconButton(":/assets/images/fast-forward-button-idle.png", ":/assets/images/fast-forward-button-pressed.png");
    fastForwardButton->setPos(1550, 25);  // MAGIC NUMBER
    addItem(fastForwardButton);
    connect(fastForwardButton, &IconButton::pressed, this, &GameScene::fastForwardButtonPressed);

    TurretSelector* turretSelector = new TurretSelector();
    turretSelector->setPos(1670, 150);  // 1670 = 1920 - 250
    addItem(turretSelector);

    // TODO: add addturret signal
    // TODO: add removeturret signal
}

void GameScene::tick() {
    qDebug() << "View Tick";
}

}  // namespace view
