#include "model/turrets/splitturret.h"

namespace model {

SplitTurret::SplitTurret(
    const Position& position,
    const SP<vector<SP<Enemy>>>& enemies)
    : MultipleTargetTurret(
          position,
          enemies,
          5,
          -1,
          10,
          20,
          10),
      _initialAttackDamage(10) {}

SplitTurret* SplitTurret::clone() const {
    return new SplitTurret(*this);
}

void SplitTurret::attack() {
    vector<SP<Enemy>> enemies = getTargetedEnemies();

    if (enemies.size() != 0) {
        _attackDamage = _initialAttackDamage / enemies.size();

        Turret::attack();
    }
}

}  // namespace model
