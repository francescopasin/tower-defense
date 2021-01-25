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
    // TODO: return SP of the added turret, if we can use SP. Otherwhise create method getTurrets()
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