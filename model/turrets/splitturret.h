#ifndef MODEL_SPLITTURRET_H_
#define MODEL_SPLITTURRET_H_

#include "model/turrets/multipletargetturret.h"

using std::shared_ptr;
using std::vector;

#define U_INT unsigned short int
#define SP shared_ptr

namespace model {

class SplitTurret : public MultipleTargetTurret {
   private:
    SP<Enemy> _lastTargetedEnemy;

   public:
    SplitTurret(const Position& position, const SP<vector<SP<Enemy>>>& enemies);
    virtual ~SplitTurret() = default;

    virtual void attack() override;
};

}  // namespace model

#endif