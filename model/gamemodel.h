#ifndef MODEL_GAMEMODEL_H_
#define MODEL_GAMEMODEL_H_

#include "game.h"

namespace model {

class GameModel {
   private:
    Game* _game;

   public:
    GameModel();
    Game::State tick();
    void addTurret(TurretType type, Position p);
    void removeTurret(U_INT index);
    float getCredits() const;
};

}  // namespace model

#endif