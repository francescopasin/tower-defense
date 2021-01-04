#ifndef TURRETS_MITRATURRET_H_
#define TURRETS_MITRATURRET_H_

#include "model/turrets/singulartargetturret.h"

using std::shared_ptr;
using std::vector;

#define U_INT unsigned short int
#define SP shared_ptr

namespace model {

class MitraTurret : public SingularTargetTurret {
   private:
    float _attackDamage;
    U_INT _attackCooldown;

   public:
    MitraTurret(const Position& position, const SP<vector<SP<Enemy>>>& enemies, U_INT attackRadius);

    virtual void attack() override;

    virtual int getCost() const override;
};

}  // namespace model

#endif