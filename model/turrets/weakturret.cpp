#include "model/turrets/weakturret.h"

namespace model {

WeakTurret::WeakTurret(
    const Position& position,
    const SP<vector<SP<Enemy>>>& enemies,
    U_INT attackRadius)
    : MultipleTargetTurret(position, enemies, attackRadius, -1),
      _attackDamage(20),
      _attackCooldown(40) {
    // TODO: choose parameters
    // Turret info:
    // attack damage: 20
    // attack speed: 40
    // max targets: infinite
}

void WeakTurret::attack() {
    vector<SP<Enemy>> enemies = getTargetedEnemies();

    if (enemies.size() != 0) {
        // There is at least one enemy to attack
        if (_attackCooldown == 0) {
            for (auto& enemy : enemies) {
                enemy->receiveAttack(_attackDamage);
            }
            // Reset cooldown
            _attackCooldown = 40;
        } else {
            _attackCooldown--;
        }
    }
}

int WeakTurret::getCost() const {
    // TODO: choose cost
    return 15;
}

}  // namespace model
