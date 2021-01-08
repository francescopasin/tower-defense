#ifndef MODEL_GAME_H_
#define MODEL_GAME_H_

#include "mylist.h"
#include "turrets/turret.h"

namespace model {

class Game {
   private:
    MyList<Turret*> _turrets;

   public:
    Game();
    void addTurret(const Turret&);
};

}  // namespace model

#endif