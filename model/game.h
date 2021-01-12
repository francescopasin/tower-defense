#ifndef MODEL_GAME_H_
#define MODEL_GAME_H_

#include <algorithm>

#include "deepptr.h"
#include "mylist.h"
#include "turrets/turret.h"
#include "wave.h"

namespace model {

class Game {
   public:
    enum State {
        Setup,
        Ready,
        InExecution,
        Lost,
        Won
    };

   private:
    vector<PathCell> _map;
    MyList<DeepPtr<Turret>> _turrets;
    vector<SP<Enemy>> _enemies;
    vector<Wave> _waves;  //? const

    vector<Wave>::iterator _currentWave;
    State _currentState;

    float _credits;  //TODO:: unsigned int?
    float _life;
    unsigned int _tick;
    U_INT _spawnCount;

    void spawnEnemy();
    void moveEnemy();
    void attack();
    void checkDeadEnemies();
    void checkWon();
    void toReady();

   public:
    Game();
    State tick();
    void setMap(const vector<Position>& map);
    void addWave(const Wave& wave);
    void addTurret(Turret& turret);
    void removeTurret(U_INT index);
    float getCredit() const;
};

}  // namespace model

#endif