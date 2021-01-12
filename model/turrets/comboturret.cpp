#include "model/turrets/comboturret.h"

namespace model {

ComboTurret::ComboTurret(
    const Position& position,
    const SP<vector<SP<Enemy>>>& enemies,
    U_INT attackRadius,
    float attackDamage,
    U_INT attackCooldown)
    : SingularTargetTurret(
          position,
          enemies,
          attackRadius,
          attackDamage,
          attackCooldown,
          20),
      _initialAttackDamage(attackDamage),
      _attackMultiplier(1) {}

void ComboTurret::attack() {
    vector<SP<Enemy>> enemies = getTargetedEnemies();

    if (enemies.size() != 0) {
        SP<Enemy> targetedEnemy = enemies[0];
        if (targetedEnemy != _lastTargetedEnemy) {
            _attackMultiplier = 1;
            _attackDamage = _initialAttackDamage;
            _lastTargetedEnemy = targetedEnemy;
        } else {
            _attackDamage = _attackDamage * _attackMultiplier;
            _attackMultiplier += 0.1;
        }

        Turret::attack();
    }
}

}  // namespace model