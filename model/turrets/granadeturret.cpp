#include "model/turrets/granadeturret.h"

namespace model {

GranadeTurret::GranadeTurret(
    const Position& position,
    const SP<vector<SP<Enemy>>>& enemies,
    U_INT attackRadius)
    : MultipleTargetTurret(position, enemies, attackRadius, 10),
      _attackDamage(100),
      _attackCooldown(80) {
    // TODO: choose parameters
    // Turret info:
    // attack damage: 100
    // attack speed: 80
    // max targets: 10
}

void GranadeTurret::attack() {
    vector<SP<Enemy>> enemies = getTargetedEnemies();

    if (enemies.size() != 0) {
        // There is at least one enemy to attack
        if (_attackCooldown == 0) {
            for (auto& enemy : enemies) {
                enemy->receiveAttack(_attackDamage);
            }
            // Reset cooldown
            _attackCooldown = 80;
        } else {
            _attackCooldown--;
        }
    }
}

int GranadeTurret::getCost() const {
    // TODO: choose cost
    return 40;
}

}  // namespace model
