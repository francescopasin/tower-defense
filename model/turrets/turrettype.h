#ifndef MODEL_TURRETTYPE_H_
#define MODEL_TURRETTYPE_H_

#include <unordered_map>

#define U_INT unsigned short int

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
     * attackDamage = 5
     * attackCooldown = 5
     * attackRadius = 2
     */
    MitraTurret,
    /**
     * Granade
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
     * attackRadius = 2
     */
    ComboTurret,
    /**
     * SplitTurret
     * MultipleTargetTurret
     * 
     * cost = 20
     * initialAttackDamage = 20
     * attackDamage = inversely proportional to targeted enemies count (equally divided between enemies)
     * attackCooldown = 20
     * attackRadius = 1
     * maxTargets = infinite
     */
    SplitTurret
    // TODO: SlowTimeTurret, MissileTurret, come Granade ma singola e più potente
};

struct TurretStats {
    U_INT cost;
    float initialAttackDamage;
    float initialAttackCooldown;
    U_INT attackRadius;
    // Ignored if SingularTargetTurret
    // Infinite if -1
    short int maxTargets;
};

const std::unordered_map<TurretType, TurretStats> turretTypes =
    {
        {TurretType::WeakTurret, TurretStats{10, 20, 20, 1, -1}},
        {TurretType::MitraTurret, TurretStats{25, 5, 5, 2, 0}},
        {TurretType::GranadeTurret, TurretStats{30, 50, 60, 3, 5}},
        {TurretType::ComboTurret, TurretStats{20, 5, 15, 2, 0}},
        {TurretType::SplitTurret, TurretStats{20, 20, 20, 1, -1}},
};

}  // namespace model

#endif