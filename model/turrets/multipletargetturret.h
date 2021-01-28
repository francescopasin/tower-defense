#ifndef MODEL_MULTIPLETARGETTURRET_H_
#define MODEL_MULTIPLETARGETTURRET_H_

#include "model/turrets/turret.h"
#include "model/turrets/turrettype.h"

using std::shared_ptr;
using std::vector;

#define U_INT unsigned short int
#define SP shared_ptr

namespace model {

class MultipleTargetTurret : public Turret {
   public:
    MultipleTargetTurret(
        const TurretType& type,
        const Position& position,
        const SP<vector<SP<Enemy>>>& enemies);
    virtual ~MultipleTargetTurret() = default;

    virtual vector<SP<Enemy>> getTargetedEnemies() const override;
};

}  // namespace model

#endif