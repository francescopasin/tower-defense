#include "model/turrets/multipletargetturret.h"

namespace model {

MultipleTargetTurret::MultipleTargetTurret(
    const Position& position,
    const SP<vector<SP<Enemy>>>& enemies,
    U_INT attackRadius,
    short int targetsAmount)
    : Turret(position, enemies, attackRadius),
      _targetsAmount(targetsAmount) {}

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
