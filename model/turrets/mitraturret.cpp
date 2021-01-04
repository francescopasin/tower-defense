#include "model/turrets/mitraturret.h"

namespace model {

MitraTurret::MitraTurret(
    const Position& position,
    const SP<vector<SP<Enemy>>>& enemies,
    U_INT attackRadius)
    : SingularTargetTurret(position, enemies, attackRadius),
      _attackDamage(15),
      _attackCooldown(10) {
    // TODO: choose parameters
    // Turret info:
    // attack damage: 15
    // attack speed: 10
}

void MitraTurret::attack() {
    vector<SP<Enemy>> enemies = getTargetedEnemies();

    if (enemies.size() != 0) {
        // There is at least one enemy to attack
        if (_attackCooldown == 0) {
            enemies[0]->receiveAttack(_attackDamage);
            // Reset cooldown
            _attackCooldown = 10;
        } else {
            _attackCooldown--;
        }
    }
}

int MitraTurret::getCost() const {
    // TODO: choose cost
    return 20;
}

}  // namespace model
