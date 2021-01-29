#include "model/turrets/turret.h"

namespace model {

Turret::Turret(
    const TurretType& type,
    const Position& position,
    const SP<vector<SP<Enemy>>>& enemies)
    : _stats(turretTypes.at(type)),
      _position(position),
      _enemies(enemies),
      _attackDamage(_stats.initialAttackDamage),
      _attackCooldown(_stats.initialAttackCooldown),
      _attackCooldownCounter(_stats.initialAttackCooldown) {}

vector<SP<Enemy>> Turret::getEnemiesInRadius() const {
    vector<SP<Enemy>> enemies = vector<SP<Enemy>>();

    for (auto& enemy : *_enemies) {
        Position enemyPosition = enemy->getCurrentCell().getPosition();
        if (enemyPosition.x >= _position.x - _stats.attackRadius &&
            enemyPosition.x <= _position.x + _stats.attackRadius &&
            enemyPosition.y >= _position.y - _stats.attackRadius &&
            enemyPosition.y <= _position.y + _stats.attackRadius) {
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
    return _stats.cost;
}

}  // namespace model
