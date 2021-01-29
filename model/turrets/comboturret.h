#ifndef MODEL_COMBOTURRET_H_
#define MODEL_COMBOTURRET_H_

#include "model/turrets/singulartargetturret.h"

using std::shared_ptr;
using std::vector;

#define U_INT unsigned short int
#define SP shared_ptr

namespace model {

class ComboTurret : public SingularTargetTurret {
   private:
    float _attackMultiplier;
    SP<Enemy> _lastTargetedEnemy;

   public:
    ComboTurret(const Position& position, const SP<vector<SP<Enemy>>>& enemies);
    virtual ~ComboTurret() = default;

    virtual void attack() override;
};

}  // namespace model

#endif