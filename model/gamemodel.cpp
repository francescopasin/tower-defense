#include "gamemodel.h"

namespace model {

GameModel::GameModel() {
    U_INT credits = 50;
    float life = 150;

    vector<Position> map;
    map.push_back(Position{0, 0});
    map.push_back(Position{0, 1});
    map.push_back(Position{1, 1});
    map.push_back(Position{2, 1});
    for (int i = 2; i < 7; i++)
        map.push_back(Position{i, 2});
    map.push_back(Position{6, 3});
    map.push_back(Position{6, 4});
    map.push_back(Position{5, 4});
    map.push_back(Position{4, 4});
    map.push_back(Position{4, 5});
    map.push_back(Position{3, 5});
    map.push_back(Position{2, 5});
    map.push_back(Position{2, 6});
    for (int i = 2; i < 8; i++)
        map.push_back(Position{i, 7});
    for (int i = 8; i < 15; i++)
        map.push_back(Position{7, i});
    map.push_back(Position{6, 14});
    map.push_back(Position{5, 14});
    map.push_back(Position{4, 14});
    map.push_back(Position{4, 13});
    map.push_back(Position{4, 12});
    map.push_back(Position{4, 11});
    map.push_back(Position{3, 11});
    map.push_back(Position{2, 11});
    for (int i = 11; i < 16; i++)
        map.push_back(Position{1, i});

    vector<Position> blockTurret;
    for (int i = 3; i < 11; i++)
        blockTurret.push_back(Position{0, i});
    for (int i = 5; i < 9; i++)
        blockTurret.push_back(Position{i, 0});
    for (int i = 3; i < 7; i++)
        blockTurret.push_back(Position{i, 9});
    for (int i = 12; i < 16; i++)
        blockTurret.push_back(Position{8, i});
    blockTurret.push_back(Position{1, 0});
    blockTurret.push_back(Position{3, 1});
    blockTurret.push_back(Position{8, 1});
    blockTurret.push_back(Position{8, 2});
    blockTurret.push_back(Position{4, 3});
    blockTurret.push_back(Position{7, 3});
    blockTurret.push_back(Position{2, 4});
    blockTurret.push_back(Position{1, 6});
    blockTurret.push_back(Position{7, 6});
    blockTurret.push_back(Position{3, 6});
    blockTurret.push_back(Position{1, 7});
    blockTurret.push_back(Position{2, 8});
    blockTurret.push_back(Position{3, 8});
    blockTurret.push_back(Position{6, 10});
    blockTurret.push_back(Position{2, 12});
    blockTurret.push_back(Position{5, 12});
    blockTurret.push_back(Position{3, 14});
    blockTurret.push_back(Position{0, 15});
    blockTurret.push_back(Position{2, 15});
    blockTurret.push_back(Position{3, 15});
    blockTurret.push_back(Position{7, 15});

    vector<Wave> wave;
    wave.push_back(Wave{100, 120, 6, 15, 0, 10});
    wave.push_back(Wave{100, 120, 10, 15, 60, 10});
    wave.push_back(Wave{50, 30, 20, 5, 60, 10});
    wave.push_back(Wave{200, 60, 6, 15, 60, 30});
    wave.push_back(Wave{300, 60, 8, 10, 60, 50});
    _game = new Game(credits, life, map, blockTurret, wave, Direction::Left);
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
    return _game->getCredits();
}
}  // namespace model