#ifndef MODEL_MULTIPLETARGETTURRET_H_
#define MODEL_MULTIPLETARGETTURRET_H_

#include "model/turrets/turret.h"

using std::shared_ptr;
using std::vector;

#define U_INT unsigned short int
#define SP shared_ptr

namespace model {

class MultipleTargetTurret : public Turret {
   private:
    // Quantity of possible targets. Infinite if -1
    short int _targetsAmount;

   public:
    MultipleTargetTurret(
        const Position& position,
        const SP<vector<SP<Enemy>>>& enemies,
        U_INT attackRadius,
        short int targetsAmount);

    virtual ~MultipleTargetTurret() = default;

    virtual void attack() = 0;

    virtual int getCost() const = 0;
    virtual vector<SP<Enemy>> getTargetedEnemies() const override;
};

}  // namespace model

#endif