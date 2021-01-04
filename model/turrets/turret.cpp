#include "model/turrets/turret.h"

namespace model {

Turret::Turret(
    const Position& position,
    const SP<vector<SP<Enemy>>>& enemies,
    U_INT attackRadius)
    : _position(position),
      _enemies(enemies),
      _attackRadius(attackRadius) {}

vector<SP<Enemy>> Turret::getEnemiesInRadius() const {
    vector<SP<Enemy>> enemies = vector<SP<Enemy>>();

    for (auto& enemy : *_enemies) {
        Position enemyPosition = enemy->getPosition();
        if (enemyPosition.x >= _position.x - _attackRadius &&
            enemyPosition.x <= _position.x + _attackRadius &&
            enemyPosition.y >= _position.y - _attackRadius &&
            enemyPosition.y <= _position.y + _attackRadius) {
            enemies.push_back(enemy);
        }
    }

    return enemies;
}

Position Turret::getPosition() const {
    return _position;
}

}  // namespace model
