#ifndef MODEL_TURRETTYPE_H_
#define MODEL_TURRETTYPE_H_

namespace model {

enum class TurretType {
    /**
     * WeakTurret
     * MultipleTargetTurret
     * 
     * cost = 10
     * attackDamage = 20
     * attackCooldown = 20
     * attackRadius = 1
     * maxTargets = infinite
     */
    WeakTurret,
    /**
     * MitraTurret
     * SingularTargetTurret
     * 
     * cost = 25
     * attackDamage = 10
     * attackCooldown = 10
     * attackRadius = 3
     */
    MitraTurret,
    /**
     * MitraTurret
     * MultipleTargetTurret
     * 
     * cost = 30
     * attackDamage = 50
     * attackCooldown = 60
     * attackRadius = 3
     * maxTargets = 5
     */
    GranadeTurret,
    /**
     * ComboTurret
     * SingularTargetTurret
     * 
     * cost = 20
     * initialAttackDamage = 5
     * attackDamage = increment every attack (reset when changes targeted enemy)
     * attackCooldown = 15
     * attackRadius = 4
     */
    ComboTurret,
    /**
     * SplitTurret
     * MultipleTargetTurret
     * 
     * cost = 10
     * initialAttackDamage = 10
     * attackDamage = inversely proportional to targeted enemies count (equally divided between enemies)
     * attackCooldown = 20
     * attackRadius = 5
     * maxTargets = infinite
     */
    SplitTurret
    // TODO: SlowTimeTurret, MissileTurret, come Granade ma singola e più potente
};

}

#endif