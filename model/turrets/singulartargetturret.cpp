#include "model/turrets/singulartargetturret.h"

namespace model {

SingularTargetTurret::SingularTargetTurret(const Position& position, const SP<vector<SP<Enemy>>>& enemies, U_INT attackRadius) : Turret(position, enemies, attackRadius) {}

vector<SP<Enemy>> SingularTargetTurret::getTargetedEnemies() const {
    vector<SP<Enemy>> enemiesInRadius = getEnemiesInRadius();
    vector<SP<Enemy>> targetedEnemies = vector<SP<Enemy>>();

    // Targets the first enemy in radius
    targetedEnemies.push_back(enemiesInRadius[0]);

    return targetedEnemies;
}

}  // namespace model
