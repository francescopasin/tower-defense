#ifndef MODEL_SINGULARTARGETTURRET_H_
#define MODEL_SINGULARTARGETTURRET_H_

#include "model/turrets/turret.h"

using std::shared_ptr;
using std::vector;

#define U_INT unsigned short int
#define SP shared_ptr

namespace model {

class SingularTargetTurret : public Turret {
   public:
    SingularTargetTurret(
        const Position& position,
        const SP<vector<SP<Enemy>>>& enemies,
        U_INT attackRadius);

    virtual ~SingularTargetTurret() = default;

    virtual void attack() = 0;

    virtual int getCost() const = 0;
    virtual vector<SP<Enemy>> getTargetedEnemies() const override;
};

}  // namespace model

#endif