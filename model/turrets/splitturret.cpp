#include "model/turrets/splitturret.h"

#include "model/turrets/turrettype.h"

namespace model {

SplitTurret::SplitTurret(const Position& position, const SP<vector<SP<Enemy>>>& enemies)
    : MultipleTargetTurret(TurretType::SplitTurret, position, enemies) {}

void SplitTurret::attack() {
    vector<SP<Enemy>> enemies = getTargetedEnemies();

    if (enemies.size() != 0) {
        _attackDamage = _stats.initialAttackDamage / enemies.size();

        Turret::attack();
    }
}

}  // namespace model
