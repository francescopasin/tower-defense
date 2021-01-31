#include "view/screens/gameScreen/enemyitem.h"

#include <QPainter>

namespace view {

EnemyItem::EnemyItem(
    QGraphicsItem *parent,
    const SP<model::Enemy> &enemy,
    qreal cellSize)
    : QGraphicsItem(parent),
      enemyData(enemy),
      _cellSize(cellSize) {
    setPosition();
}

void EnemyItem::setPosition() {
    model::PathCell currentCell = enemyData->getCurrentCell();
    float cellPosition = enemyData->getCellPosition();
    bool firstHalf = cellPosition < 50;

    qreal x = currentCell.x * _cellSize;
    qreal y = currentCell.y * _cellSize;

    // Get direction
    if (firstHalf) {
        switch (currentCell.from) {
            case model::Direction::Left:
                x += cellPosition * _cellSize / 100;
                y += _cellSize / 2;
                break;
            case model::Direction::Up:
                x += _cellSize / 2;
                y += cellPosition * _cellSize / 100;
                break;
            case model::Direction::Right:
                x -= cellPosition * _cellSize / 100 - _cellSize;
                y += _cellSize / 2;
                break;
            case model::Direction::Down:
                x += _cellSize / 2;
                y -= cellPosition * _cellSize / 100 - _cellSize;
                break;
        }
    } else {
        switch (currentCell.to) {
            case model::Direction::Left:
                x -= cellPosition * _cellSize / 100 - _cellSize;
                y += _cellSize / 2;
                break;
            case model::Direction::Up:
                x += _cellSize / 2;
                y -= cellPosition * _cellSize / 100 - _cellSize;
                break;
            case model::Direction::Right:
                x += cellPosition * _cellSize / 100;
                y += _cellSize / 2;
                break;
            case model::Direction::Down:
                x += _cellSize / 2;
                y += cellPosition * _cellSize / 100;
                break;
        }
    }

    // 15 = enemy size / 2 - align to center
    x -= 25;
    y -= 25;

    setPos(x, y);
}

QRectF EnemyItem::boundingRect() const {
    return QRectF(0, 0, 50, 55);
}

void EnemyItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(Qt::black);
    painter->setBrush(QColor::fromRgb(255, 51, 204));

    painter->drawRect(0, 0, 50, 50);

    painter->setPen(Qt::black);
    painter->setBrush(Qt::white);

    painter->drawRect(0, 50, 50, 5);

    float currentHealth = enemyData->getHealth();
    if (currentHealth < 0) {
        currentHealth = 0;
    }
    float initialtHealth = enemyData->getInitialHealth();

    float widthAdvance = (50 * currentHealth) / initialtHealth;
    painter->setPen(Qt::NoPen);

    if (widthAdvance <= 15) {
        painter->setBrush(Qt::red);
    } else {
        painter->setBrush(Qt::green);
    }

    painter->drawRect(1, 51, widthAdvance - 1, 3);

    // // TODO: temp. For debugging
    // QFont font = painter->font();
    // font.setPixelSize(25);
    // painter->setFont(font);
    // painter->setPen(Qt::white);
    // painter->drawText(QRect(0, 0, 50, 50), Qt::AlignCenter, QString::number(enemyData->getHealth()));
}

void EnemyItem::tick() {
    // Update position
    setPosition();

    // TODO: check health

    update();
}

bool EnemyItem::isDead() const {
    // Check if the enemyData has been deleted from the model
    if (enemyData->getHealth() <= 0) {
        return true;
    }

    return false;
}

bool EnemyItem::hasEnemyData(const SP<model::Enemy> &enemy) const {
    return enemy == enemyData;
}

}  // namespace view
