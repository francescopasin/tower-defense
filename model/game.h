#ifndef MODEL_GAME_H_
#define MODEL_GAME_H_

#include <algorithm>
#include <memory>

#include "exception.h"
#include "mylist.h"
#include "sharedptr.h"
#include "turrets/comboturret.h"
#include "turrets/multipletargetturret.h"
#include "turrets/singulartargetturret.h"
#include "turrets/splitturret.h"
#include "turrets/turrettype.h"
#include "wave.h"

using std::shared_ptr;
#define SP shared_ptr

namespace model {

class Game {
   public:
    enum State {
        Ready,
        InExecution,
        Lost,
        Won
    };

   private:
    vector<PathCell> _map;
    vector<Position> _blockedCellsMap;
    MyList<SharedPtr<Turret>> _turrets;
    vector<SP<Enemy>> _enemies;
    SP<Enemy> _lastTickSpawnedEnemy;
    vector<Wave> _waves;
    vector<Wave>::iterator _currentWave;
    State _currentState;

    U_INT _credits;
    float _life;
    unsigned int _tick;
    U_INT _spawnCount;

    void spawnEnemy();
    void moveEnemies();
    void attack();
    void checkDeadEnemies();
    void checkWon();

    void setMap(vector<Position>& map, Direction first);

   public:
    Game(U_INT credits, float life, vector<Position>& map, const vector<Position>& blockedCellsMap, const vector<Wave>& waves, Direction first);
    State tick();
    void addTurret(TurretType type, Position p);
    void removeTurret(U_INT index);

    SP<Enemy> lastTickSpawnedEnemy() const;

    U_INT getCredits() const;
    float getLife() const;
    vector<PathCell> getMap() const;
    vector<Position> getBlockedCellsMap() const;
};

}  // namespace model

#endif
