#include "model/turrets/granadeturret.h"

#include "model/turrets/turrettype.h"

namespace model {

GranadeTurret::GranadeTurret(const Position& position, const SP<vector<SP<Enemy>>>& enemies)
    : Turret(TurretType::GranadeTurret, position, enemies) {}

bool GranadeTurret::attack() {
    vector<SP<Enemy>> enemies = getTargetedEnemies();

    if (enemies.size() != 0) {
        if (_attackCooldownCounter == 0) {
            for (auto enemy : enemies) {
                enemy->receiveAttack(_attackDamage);
                // Reduce damage for every enemy
                _attackDamage -= 10;
            }
            // Reset cooldown
            _attackCooldownCounter = _attackCooldown;
            _hasAttackedLastTick = true;
            // Restore damage
            _attackDamage = _stats.initialAttackDamage;

            return true;
        } else {
            _attackCooldownCounter--;
            _hasAttackedLastTick = false;
        }
    }

    return false;
}

}  // namespace model
