#ifndef MODEL_TURRET_H_
#define MODEL_TURRET_H_

#include <memory>
#include <vector>

#include "model/enemy.h"
#include "model/position.h"

using std::shared_ptr;
using std::vector;

#define U_INT unsigned short int
#define SP shared_ptr

namespace model {

class Turret {
   private:
    const Position _position;
    SP<vector<SP<Enemy>>> _enemies;
    const U_INT _attackRadius;
    const U_INT _cost;

   protected:
    float _attackDamage;
    U_INT _attackCooldown;
    U_INT _attackCooldownCounter;

    vector<SP<Enemy>>
    getEnemiesInRadius() const;

   public:
    Turret(
        const Position& position,
        const SP<vector<SP<Enemy>>>& enemies,
        U_INT attackRadius,
        float attackDamage,
        U_INT attackCooldown,
        U_INT cost);
    virtual ~Turret() = default;

    virtual void attack();

    virtual vector<SP<Enemy>> getTargetedEnemies() const = 0;

    Position getPosition() const;
    U_INT getCost() const;
};

}  // namespace model

#endif