#include "model/turrets/turret.h"

namespace model {

Turret::Turret(
    const Position& position,
    const SP<vector<SP<Enemy>>>& enemies,
    U_INT attackRadius,
    float attackDamage,
    U_INT attackCooldown,
    U_INT cost)
    : _position(position),
      _enemies(enemies),
      _attackRadius(attackRadius),
      _cost(cost),
      _attackDamage(attackDamage),
      _attackCooldown(attackCooldown),
      _attackCooldownCounter(attackCooldown) {}

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

void Turret::attack() {
    vector<SP<Enemy>> enemies = getTargetedEnemies();

    if (enemies.size() != 0) {
        // There is at least one enemy to attack
        if (_attackCooldownCounter == 0) {
            for (auto& enemy : enemies) {
                enemy->receiveAttack(_attackDamage);
            }
            // Reset cooldown
            _attackCooldownCounter = _attackCooldown;
        } else {
            _attackCooldownCounter--;
        }
    }
}

Position Turret::getPosition() const {
    return _position;
}

U_INT Turret::getCost() const {
    return _cost;
}

}  // namespace model
