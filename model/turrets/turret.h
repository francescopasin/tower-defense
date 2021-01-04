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
    Position _position;
    SP<vector<SP<Enemy>>> _enemies;
    U_INT _attackRadius;

   protected:
    vector<SP<Enemy>> getEnemiesInRadius() const;

   public:
    Turret(const Position& position, const SP<vector<SP<Enemy>>>& enemies, U_INT attackRadius);

    virtual ~Turret() = default;

    virtual void attack() = 0;

    virtual int getCost() const = 0;
    virtual vector<SP<Enemy>> getTargetedEnemies() const = 0;

    Position getPosition() const;
};

}  // namespace model

#endif