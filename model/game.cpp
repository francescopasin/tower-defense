#include "Game.h"

namespace model {

Game::Game(U_INT credits,
           float life,
           vector<Position>& map,
           const vector<Position>& blockedCellsMap,
           const vector<Wave>& waves,
           Direction first) : _blockedCellsMap(blockedCellsMap), _waves(waves), _currentWave(_waves.end()), _currentState(State::Ready), _credits(credits), _life(life), _tick(0), _spawnCount(0) {
    setMap(map, first);
    _currentWave = _waves.begin();
}

void Game::addTurret(TurretType type, Position p) {
    Turret* temp;
    switch (type) {
        case TurretType::ComboTurret:
            temp = new ComboTurret(p, SP<vector<SP<Enemy>>>(&_enemies));
            break;
        case TurretType::GranadeTurret:
            temp = new MultipleTargetTurret(p, SP<vector<SP<Enemy>>>(&_enemies), 30, 10, 20, 10, 50);
            break;
        case TurretType::MitraTurret:
            temp = new SingularTargetTurret(p, SP<vector<SP<Enemy>>>(&_enemies), 10, 20, 10, 50);
            break;
        case TurretType::SplitTurret:
            temp = new SplitTurret(p, SP<vector<SP<Enemy>>>(&_enemies));
            break;
        default:  // Weak Turret
            temp = new SingularTargetTurret(p, SP<vector<SP<Enemy>>>(&_enemies), 5, 10, 5, 25);
            break;
    }
    bool trovato = false;
    for (auto i = _blockedCellsMap.cbegin(); i != _blockedCellsMap.cend() && !trovato; ++i)
        trovato = (*i) == p;
    for (auto i = _map.cbegin(); i != _map.cend() && !trovato; ++i)
        trovato = i->getPosition() == p;
    if (trovato) {
        _turrets.pushBack(temp);
    } else {
        throw new turret_error("You can't insert a turret in this position");
    }
}

void Game::removeTurret(U_INT index) {
    // TODO: restore some credits
    _turrets.erase(index);
}

float Game::getCredits() const {
    return _credits;
}

void Game::setMap(vector<Position>& map, Direction first) {
    auto it = std::unique(map.begin(), map.end());
    bool wasUnique = (it == map.end());
    PathCell prev;
    Direction from;
    if (wasUnique) {
        for (auto i = map.cbegin(); i != map.cend(); ++i) {
            auto next = i + 1;
            if (i == map.cbegin()) {
                from = first;
            } else {
                switch (prev.to) {
                    case Direction::Up:
                        from = Direction::Down;
                        break;
                    case Direction::Down:
                        from = Direction::Up;
                        break;
                    case Direction::Left:
                        from = Direction::Right;
                        break;
                    default:
                        from = Direction::Left;
                        break;
                }
            }
            if (next != map.cend()) {
                if ((i->x == next->x + 1) && (i->y == next->y)) {
                    _map.push_back(PathCell{i->x, i->y, from, Direction::Right});
                } else if ((i->x == next->x) && (i->y == next->y + 1)) {
                    _map.push_back(PathCell{i->x, i->y, from, Direction::Up});
                } else if ((i->x == next->x - 1) && (i->y == next->y)) {
                    _map.push_back(PathCell{i->x, i->y, from, Direction::Left});
                } else if ((i->x == next->x) && (i->y == next->y - 1)) {
                    _map.push_back(PathCell{i->x, i->y, from, Direction::Down});
                } else {
                    throw new path_error("This is not a correct path, some cells are disconnected");
                }
                prev = _map.at(_map.size() - 1);
            }
        }
    } else {
        throw new path_error("This is not a correct path, you can't go through the same cell twice");
    }
}

void Game::moveEnemies() {
    for (auto i = _enemies.begin(); i != _enemies.end(); ++i) {
        _life -= (*i)->move();
        i = _enemies.erase(i) - 1;
    }
    if (_life <= 0)
        _currentState = State::Lost;
}

void Game::spawnEnemy() {
    if (_currentWave != _waves.end()) {
        _spawnCount++;
        if (_currentWave->enemiesNumber > 0) {
            if (_spawnCount >= _currentWave->startsAfter && (_spawnCount - _currentWave->startsAfter) % _currentWave->enemiesIntervalTick == 0) {
                _enemies.push_back(SP<Enemy>(new Enemy(_map, _currentWave->enemiesHealth, _currentWave->enemiesSpeed, _currentWave->enemiesAttackDamage)));
                _currentWave->enemiesNumber--;
            }
        } else {
            _currentWave++;
            _spawnCount = 0;
        }
    }
}

void Game::attack() {
    for (auto i = _turrets.begin(); i != _turrets.end(); ++i) {
        (*i)->attack();
    }
}

void Game::checkDeadEnemies() {
    for (auto i = _enemies.begin(); i != _enemies.end(); ++i) {
        if ((*i)->getHealth() <= 0) {
            i = _enemies.erase(i);
            i--;
        }
    }
}

void Game::checkWon() {
    if (_enemies.size() == 0 && _currentWave == _waves.end())
        _currentState = State::Won;
}

Game::State Game::tick() {
    if (_currentState == State::Ready)
        _currentState = State::InExecution;

    if (_currentState == State::InExecution) {
        _tick++;
        moveEnemies();
        spawnEnemy();
        attack();
        checkDeadEnemies();
        checkWon();
    }
    return _currentState;
}

}  // namespace model
