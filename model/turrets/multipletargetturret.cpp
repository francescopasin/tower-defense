#include "model/turrets/multipletargetturret.h"

namespace model {

MultipleTargetTurret::MultipleTargetTurret(
    const Position& position,
    const SP<vector<SP<Enemy>>>& enemies,
    U_INT attackRadius,
    short int targetsAmount,
    float attackDamage,
    U_INT attackCooldown,
    U_INT cost)
    : Turret(position, enemies, attackRadius, attackDamage, attackCooldown, cost),
      _targetsAmount(targetsAmount) {}

MultipleTargetTurret* MultipleTargetTurret::clone() const {
    return new MultipleTargetTurret(*this);
}

vector<SP<Enemy>> MultipleTargetTurret::getTargetedEnemies() const {
    vector<SP<Enemy>> enemiesInRadius = getEnemiesInRadius();
    vector<SP<Enemy>> targetedEnemies = vector<SP<Enemy>>();

    U_INT targetsAmount = _targetsAmount;

    if (_targetsAmount == -1) {
        targetsAmount = enemiesInRadius.size();
    }

    for (U_INT i = 0; i < targetsAmount; i++) {
        targetedEnemies.push_back(enemiesInRadius[i]);
    }

    return targetedEnemies;
}

}  // namespace model
