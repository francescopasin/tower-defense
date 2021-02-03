#ifndef MODEL_GAME_H_
#define MODEL_GAME_H_

#include <algorithm>
#include <vector>

#include "app/shortcuts.h"
#include "model/exception.h"
#include "model/mylist.h"
#include "model/turrets/comboturret.h"
#include "model/turrets/multipletargetturret.h"
#include "model/turrets/singulartargetturret.h"
#include "model/turrets/splitturret.h"
#include "model/turrets/turrettype.h"
#include "model/wave.h"

using std::vector;

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
    SP<vector<SP<Enemy>>> _enemies;

    SP<Enemy> _lastTickSpawnedEnemy;
    vector<SharedPtr<Turret>> _lastTickAttackingTurrets;

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
    void reorderEnemies();

   public:
    Game(U_INT credits, float life, vector<Position>& map, const vector<Position>& blockedCellsMap, const vector<Wave>& waves, Direction first);
    State tick();
    SharedPtr<Turret> addTurret(TurretType type, Position p);
    void removeTurret(Position p);

    SP<Enemy> lastTickSpawnedEnemy() const;
    vector<SharedPtr<Turret>> lastTickAttackingTurrets() const;

    void setMap(vector<Position>& map, Direction first);
    void setBlocked(vector<Position>& map);

    U_INT getCredits() const;
    float getLife() const;
    const vector<PathCell>& getMap() const;
    const vector<Position>& getBlockedCellsMap() const;

    static std::string validateMap(vector<Position>& map);
};

}  // namespace model

#endif
