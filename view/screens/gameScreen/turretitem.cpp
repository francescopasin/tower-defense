#include "view/screens/gameScreen/turretitem.h"

#include <QPainter>

#include "app/shortcuts.h"
#include "model/turrets/turrettype.h"

namespace view {

TurretItem::TurretItem(
    QGraphicsItem *parent,
    const SP<model::Turret> &turret,
    model::TurretType turretType,
    qreal cellSize)
    : QGraphicsItem(parent),
      turretData(turret),
      type(turretType),
      _cellSize(cellSize) {
    setPosition();
}

void TurretItem::setPosition() {
    model::Position position = turretData->getPosition();
    setPos(position.x * _cellSize, position.y * _cellSize);
}

QRectF TurretItem::boundingRect() const {
    return QRectF(0, 0, _cellSize, _cellSize);
}

void TurretItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(Qt::NoPen);

    QPixmap pixmap;

    switch (type) {
        case model::TurretType::WeakTurret:
            pixmap = QPixmap(":/assets/images/turrets/weak-turret.png");
            break;
        case model::TurretType::MitraTurret:
            pixmap = QPixmap(":/assets/images/turrets/mitra-turret.png");
            break;
        case model::TurretType::GranadeTurret:
            pixmap = QPixmap(":/assets/images/turrets/granade-turret.png");
            break;
        case model::TurretType::ComboTurret:
            pixmap = QPixmap(":/assets/images/turrets/combo-turret.png");
            break;
        case model::TurretType::SplitTurret:
            pixmap = QPixmap(":/assets/images/turrets/split-turret.png");
            break;
        case model::TurretType::SlowTimeTurret:
            pixmap = QPixmap(":/assets/images/turrets/slowtime-turret.png");
            break;
    }

    painter->drawPixmap(QRect(0, 0, _cellSize, _cellSize), pixmap);
}

model::Position TurretItem::getGridPosition() const {
    return turretData->getPosition();
}

void TurretItem::attack(const vector<EnemyItem *> &enemies) {
    vector<SP<model::Enemy>> targetedEnemies = turretData->getTargetedEnemies();

    for (auto enemy : targetedEnemies) {
        // Find associated EnemyItem
        for (auto enemyItem : enemies) {
            if (enemyItem->hasEnemyData(enemy)) {
                // Spawn projectile

                // TODO: mapFromScene not working - calculate enemy pos relative to gridfield
                //QPointF enemyPos = mapToParent(mapFromScene(enemyItem->pos()));

                // TODO: TEMP
                QPointF enemyPos(enemyItem->pos().x() + 50, enemyItem->pos().y() + 50);  // 50: MAGIC NUMBER

                emit spawnProjectile(
                    QPointF(pos().x() + ((_cellSize - 10) / 2), pos().y() + ((_cellSize - 10) / 2)),
                    QPointF(enemyPos.x() + enemyItem->boundingRect().x() / 2, enemyPos.y() + enemyItem->boundingRect().y() / 2));
            }
        }
    }
}

bool TurretItem::hasTurretData(const SP<model::Turret> &turret) const {
    return turret == turretData;
}

}  // namespace view
