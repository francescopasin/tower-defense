#include "model/turrets/comboturret.h"

#include "model/turrets/turrettype.h"

namespace model {

ComboTurret::ComboTurret(const Position& position, const SP<vector<SP<Enemy>>>& enemies)
    : SingularTargetTurret(
          TurretType::ComboTurret,
          position,
          enemies),
      _attackDamage(_stats.initialAttackDamage),
      _attackMultiplier(1) {}

void ComboTurret::attack() {
    vector<SP<Enemy>> enemies = getTargetedEnemies();

    if (enemies.size() != 0) {
        SP<Enemy> targetedEnemy = enemies[0];
        if (targetedEnemy != _lastTargetedEnemy) {
            _attackMultiplier = 1;
            _attackDamage = _stats.initialAttackDamage;
            _lastTargetedEnemy = targetedEnemy;
        } else {
            _attackDamage = _attackDamage * _attackMultiplier;
            _attackMultiplier += 0.1;
        }

        Turret::attack();
    }
}

}  // namespace model
