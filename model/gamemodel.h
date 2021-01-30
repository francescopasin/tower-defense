#ifndef MODEL_GAMEMODEL_H_
#define MODEL_GAMEMODEL_H_

#include <memory>

#include "model/game.h"

using std::shared_ptr;
#define SP shared_ptr

namespace model {

class GameModel {
   private:
    Game* _game;

   public:
    GameModel();
    Game::State tick();

    void reset();

    SharedPtr<Turret> addTurret(TurretType type, Position p);
    void removeTurret(Position p);

    SP<Enemy> lastTickSpawnedEnemy() const;

    void setMap(vector<Position>& map, Direction first);
    void setBlocked(vector<Position>& map);

    U_INT
    getCredits() const;
    float getLife() const;
    const vector<PathCell>& getMap() const;
    const vector<Position>& getBlockedCellsMap() const;

    static std::string validateMap(vector<Position>& map);
};

}  // namespace model

#endif