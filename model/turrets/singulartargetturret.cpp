#include "model/turrets/singulartargetturret.h"

namespace model {

SingularTargetTurret::SingularTargetTurret(
    const TurretType& type,
    const Position& position,
    const SP<vector<SP<Enemy>>>& enemies)
    : Turret(type, position, enemies) {}

vector<SP<Enemy>> SingularTargetTurret::getTargetedEnemies() const {
    vector<SP<Enemy>> enemiesInRadius = getEnemiesInRadius();
    vector<SP<Enemy>> targetedEnemies = vector<SP<Enemy>>();

    // Targets the first enemy in radius
    if (enemiesInRadius.size() > 0) {
        targetedEnemies.push_back(enemiesInRadius[0]);
    }

    return targetedEnemies;
}

}  // namespace model
