#include "gamemodel.h"

namespace model {

GameModel::GameModel(U_INT credits, float life, const vector<Position>& map) {
    vector<Wave> temp;
    temp.push_back(Wave{100, 120, 6, 15, 0, 10});
    temp.push_back(Wave{100, 120, 10, 15, 60, 10});
    temp.push_back(Wave{50, 30, 20, 5, 60, 10});
    temp.push_back(Wave{200, 60, 6, 15, 60, 30});
    temp.push_back(Wave{300, 60, 8, 10, 60, 50});
    _game = new Game(credits, life, map, temp);
}
Game::State GameModel::tick() {
    return _game->tick();
}
void GameModel::addTurret(TurretType type, Position p) {
    return _game->addTurret(type, p);
}
void GameModel::removeTurret(U_INT index) {
    return _game->removeTurret(index);
}
float GameModel::getCredits() const {
    return _game->getCredits(9;)
}
}  // namespace model