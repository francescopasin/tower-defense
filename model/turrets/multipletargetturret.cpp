#include "model/turrets/multipletargetturret.h"

namespace model {

MultipleTargetTurret::MultipleTargetTurret(
    const TurretType& type,
    const Position& position,
    const SP<vector<SP<Enemy>>>& enemies)
    : Turret(type, position, enemies) {}

vector<SP<Enemy>> MultipleTargetTurret::getTargetedEnemies() const {
    vector<SP<Enemy>> enemiesInRadius = getEnemiesInRadius();
    vector<SP<Enemy>> targetedEnemies = vector<SP<Enemy>>();

    U_INT targetsAmount;

    if (_stats.maxTargets == -1) {
        targetsAmount = enemiesInRadius.size();
    } else {
        targetsAmount = _stats.maxTargets;
    }

    for (U_INT i = 0; i < targetsAmount && i < enemiesInRadius.size(); i++) {
        targetedEnemies.push_back(enemiesInRadius[i]);
    }

    return targetedEnemies;
}

}  // namespace model
