#ifndef MODEL_TURRET_H_
#define MODEL_TURRET_H_

#include <memory>
#include <vector>

#include "model/enemy.h"
#include "model/position.h"
#include "model/turrets/turrettype.h"

using std::shared_ptr;
using std::vector;

#define U_INT unsigned short int
#define SP shared_ptr

namespace model {

class Turret {
   private:
    const Position _position;
    SP<vector<SP<Enemy>>> _enemies;

   protected:
    const TurretStats _stats;
    // Attack damage and cooldown are protected in order to let child turrets do specials attack
    float _attackDamage;
    float _attackCooldown;
    U_INT _attackCooldownCounter;

    bool _hasAttackedLastTick;

    vector<SP<Enemy>>
    getEnemiesInRadius() const;

   public:
    Turret(
        const TurretType& type,
        const Position& position,
        const SP<vector<SP<Enemy>>>& enemies);
    virtual ~Turret() = default;

    virtual bool attack();

    virtual vector<SP<Enemy>> getTargetedEnemies() const = 0;

    Position getPosition() const;

    U_INT getCost() const;
    bool hasAttackedLastTick() const;
};

}  // namespace model

#endif