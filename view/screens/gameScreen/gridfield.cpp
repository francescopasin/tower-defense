#include "view/screens/gameScreen/gridfield.h"

#include "view/screens/gameScreen/turretitem.h"

namespace view {

GridField::GridField(
    const QSize &size,
    const vector<model::PathCell> &path,
    const vector<model::Position> blockedCells)
    : _size(size),
      _path(path),
      _blockedCells(blockedCells) {
    setFlag(ItemHasNoContents);

    createGameGrid();
}

QRectF GridField::boundingRect() const {
    return QRectF(0, 0, _size.width(), _size.height());
}

void GridField::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);
    Q_UNUSED(painter);
}

void GridField::createGameGrid() {
    qreal size = _size.height() / 9;

    // Path Cells
    // ========================================================================
    for (auto i = _path.begin(); i != _path.end(); i++) {
        GridCell *cell;

        if (i == _path.begin()) {
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

            cell = new GridCell(this, i->getPosition(), size, GridCellType::PathStart, tile);
        } else if (i == _path.end() - 1) {
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

            cell = new GridCell(this, i->getPosition(), size, GridCellType::PathEnd, tile);
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

            cell = new GridCell(this, i->getPosition(), size, GridCellType::Path, tile);
        }

        cell->setPos(i->x * size, i->y * size);
    }

    // Blocked Cells
    // ========================================================================
    for (auto i = _blockedCells.begin(); i != _blockedCells.end(); i++) {
        GridCell *cell = new GridCell(this, *i, size, GridCellType::Blocked);
        cell->setPos(i->x * size, i->y * size);
    }

    // Free Cells
    // ========================================================================
    bool isFree = true;

    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 9; j++) {
            isFree = true;

            for (auto pathCell : _path) {
                if (pathCell.x == i && pathCell.y == j) {
                    isFree = false;
                    break;
                }
            }

            for (auto blockedCell : _blockedCells) {
                if (blockedCell.x == i && blockedCell.y == j) {
                    isFree = false;
                    break;
                }
            }

            if (isFree) {
                GridCell *cell = new GridCell(this, model::Position{i, j}, size, GridCellType::Free);
                interactiveCells.push_back(cell);
                connect(cell, &GridCell::pressed, this, &GridField::selectCell);
                cell->setPos(i * size, j * size);
            }
        }
    }
}

void GridField::selectCell(GridCell *cell) {
    for (auto c : interactiveCells) {
        if (c->isSelected()) {
            c->setSelected(false);
        }
    }

    if (cell != nullptr) {
        cell->setSelected(true);

        emit cellPressed(cell->getType(), cell->pos());
    }
}

void GridField::addTurretItem(const model::SharedPtr<model::Turret> &turret, model::TurretType turretType) {
    // Set cell as occupied
    for (auto c : interactiveCells) {
        if (c->getGridPosition() == turret->getPosition()) {
            c->setType(GridCellType::Occupied);
        }
    }

    // Create turret
    TurretItem *turretItem = new TurretItem(this, turret, turretType, 96);  // TODO: fix all cell sizes (dynamics)
    // TODO: add tick event
}

model::Position GridField::getSelectedCellPosition() const {
    for (auto c : interactiveCells) {
        if (c->isSelected()) {
            return c->getGridPosition();
        }
    }

    // TODO: handle no cell selected (shouldn't happen)
}
}  // namespace view
