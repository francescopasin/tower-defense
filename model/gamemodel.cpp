#include "model/gamemodel.h"

namespace model {

GameModel::GameModel() : _game(nullptr) {
    reset();
}

Game::State GameModel::tick() {
    return _game->tick();
}

void GameModel::reset() {
    U_INT credits = 500;
    float life = 150;

    vector<Position> map;
    vector<Position> blockedCellsMap;

    if (_game) {
        // Get current game map

        // TODO: not necessary when level selection is included
        for (auto cell : _game->getMap()) {
            map.push_back(cell.getPosition());
        }

        blockedCellsMap = _game->getBlockedCellsMap();
    } else {
        map.push_back(Position{0, 0});
        map.push_back(Position{1, 0});
        map.push_back(Position{1, 1});
        map.push_back(Position{1, 2});

        for (U_INT i = 2; i < 7; i++) {
            map.push_back(Position{2, i});
        }

        map.push_back(Position{3, 6});
        map.push_back(Position{4, 6});
        map.push_back(Position{4, 5});
        map.push_back(Position{4, 4});
        map.push_back(Position{5, 4});
        map.push_back(Position{5, 3});
        map.push_back(Position{5, 2});
        map.push_back(Position{6, 2});

        for (U_INT i = 2; i < 8; i++) {
            map.push_back(Position{7, i});
        }

        for (U_INT i = 8; i < 15; i++) {
            map.push_back(Position{i, 7});
        }

        map.push_back(Position{14, 6});
        map.push_back(Position{14, 5});
        map.push_back(Position{14, 4});
        map.push_back(Position{13, 4});
        map.push_back(Position{12, 4});
        map.push_back(Position{11, 4});
        map.push_back(Position{11, 3});
        map.push_back(Position{11, 2});

        for (U_INT i = 11; i < 16; i++) {
            map.push_back(Position{i, 1});
        }

        for (U_INT i = 3; i < 11; i++) {
            blockedCellsMap.push_back(Position{i, 0});
        }

        for (U_INT i = 5; i < 9; i++) {
            blockedCellsMap.push_back(Position{0, i});
        }

        for (U_INT i = 3; i < 7; i++) {
            blockedCellsMap.push_back(Position{9, i});
        }

        for (U_INT i = 12; i < 16; i++) {
            blockedCellsMap.push_back(Position{i, 8});
        }

        blockedCellsMap.push_back(Position{0, 1});
        blockedCellsMap.push_back(Position{1, 3});
        blockedCellsMap.push_back(Position{1, 8});
        blockedCellsMap.push_back(Position{2, 8});
        blockedCellsMap.push_back(Position{3, 4});
        blockedCellsMap.push_back(Position{3, 7});
        blockedCellsMap.push_back(Position{4, 2});
        blockedCellsMap.push_back(Position{6, 1});
        blockedCellsMap.push_back(Position{6, 7});
        blockedCellsMap.push_back(Position{6, 3});
        blockedCellsMap.push_back(Position{7, 1});
        blockedCellsMap.push_back(Position{8, 2});
        blockedCellsMap.push_back(Position{8, 3});
        blockedCellsMap.push_back(Position{10, 6});
        blockedCellsMap.push_back(Position{12, 2});
        blockedCellsMap.push_back(Position{12, 5});
        blockedCellsMap.push_back(Position{14, 3});
        blockedCellsMap.push_back(Position{15, 0});
        blockedCellsMap.push_back(Position{15, 2});
        blockedCellsMap.push_back(Position{15, 3});
        blockedCellsMap.push_back(Position{15, 7});
    }

    vector<Wave> wave;

    // TODO: temp. only for debugging
    wave.push_back(Wave{100, 20, 10, 10, 30, 50, 10});
    /*
    wave.push_back(Wave{100, 120, 10, 6, 15, 0});
    wave.push_back(Wave{100, 120, 10, 10, 15, 60});
    wave.push_back(Wave{50, 30, 10, 20, 5, 60});
    wave.push_back(Wave{200, 60, 30, 6, 15, 60});
    wave.push_back(Wave{300, 60, 50, 8, 10, 60});
    */

    if (_game) {
        delete _game;
    }

    _game = new Game(credits, life, map, blockedCellsMap, wave, Direction::Left);
}

SP<Turret> GameModel::addTurret(TurretType type, Position p) {
    return _game->addTurret(type, p);
}

void GameModel::removeTurret(Position p) {
    return _game->removeTurret(p);
}

SP<Enemy> GameModel::lastTickSpawnedEnemy() const {
    return _game->lastTickSpawnedEnemy();
}

vector<SP<Turret>> GameModel::lastTickAttackingTurrets() const {
    return _game->lastTickAttackingTurrets();
}

U_INT GameModel::getCredits() const {
    return _game->getCredits();
}

float GameModel::getLife() const {
    return _game->getLife();
}

const vector<PathCell>& GameModel::getMap() const {
    return _game->getMap();
}

const vector<Position>& GameModel::getBlockedCellsMap() const {
    return _game->getBlockedCellsMap();
}

std::string GameModel::validateMap(vector<Position>& map) {
    return Game::validateMap(map);
}

void GameModel::setMap(vector<Position>& map, Direction first) {
    _game->setMap(map, first);
}

void GameModel::setBlocked(vector<Position>& map) {
    _game->setBlocked(map);
}

}  // namespace model
