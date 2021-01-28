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

struct TurretStats {
    U_INT cost;
    float initialAttackDamage;
    float initialAttackCooldown;
    U_INT attackRadius;
};

const std::unordered_map<TurretType, TurretStats> turretTypes =
    {
        {TurretType::WeakTurret, TurretStats{10, 20, 20, 1}},
        {TurretType::MitraTurret, TurretStats{25, 10, 10, 3}},
        {TurretType::GranadeTurret, TurretStats{30, 50, 60, 3}},
        {TurretType::ComboTurret, TurretStats{20, 5, 15, 4}},
        {TurretType::SplitTurret, TurretStats{10, 10, 20, 5}},
};

}  // namespace model

#endif