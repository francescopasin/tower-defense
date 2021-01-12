#include "model/turrets/splitturret.h"

namespace model {

SplitTurret::SplitTurret(
    const Position& position,
    const SP<vector<SP<Enemy>>>& enemies,
    U_INT attackRadius,
    float attackDamage,
    U_INT attackCooldown)
    : MultipleTargetTurret(
          position,
          enemies,
          attackRadius,
          -1,
          attackDamage,
          attackCooldown,
          10),
      _initialAttackDamage(attackDamage) {}

void SplitTurret::attack() {
    vector<SP<Enemy>> enemies = getTargetedEnemies();

    if (enemies.size() != 0) {
        _attackDamage = _initialAttackDamage / enemies.size();

        Turret::attack();
    }
}

}  // namespace model