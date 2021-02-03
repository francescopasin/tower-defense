#ifndef MODEL_GRANADETURRET_H_
#define MODEL_GRANADETURRET_H_

#include "app/shortcuts.h"
#include "model/turrets/multipletargetturret.h"

using std::vector;

namespace model {

class GranadeTurret : public MultipleTargetTurret {
   private:
    SP<Enemy> _lastTargetedEnemy;

   public:
    GranadeTurret(const Position& position, const SP<vector<SP<Enemy>>>& enemies);
    virtual ~GranadeTurret() = default;

    virtual bool attack() override;
};
}  // namespace model

#endif