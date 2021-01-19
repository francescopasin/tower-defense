#include "Game.h"

namespace model {

Game::Game(U_INT credits,
           float life,
           const vector<Position>& map,
           const vector<Wave>& waves) : _credits(credits), _life(life), _tick(0), _currentWave(_waves.end()), _spawnCount(0), _currentState(State::Ready) {
    setMap(map);
    for (auto i = waves.cbegin(); i != waves.cend(); ++i) {
        _waves.push_back(*i);
    }
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
    _turrets.pushBack(temp);
}

void Game::removeTurret(U_INT index) {
    _turrets.erase(index);
}

float Game::getCredits() const {
    return _credits;
}

void Game::setMap(const vector<Position>& map) {
    auto it = std::unique(map.begin(), map.end());
    bool wasUnique = (it == map.end());
    if (wasUnique) {
        for (auto i = map.cbegin(); i != map.cend(); ++i) {
            auto next = i + 1;
            if (next != map.cend()) {
                if ((i->x == next->x + 1) && (i->y == next->y)) {
                    _map.push_back(PathCell{i->x, i->y, Direction::Right});
                } else if ((i->x == next->x) && (i->y == next->y + 1)) {
                    _map.push_back(PathCell{i->x, i->y, Direction::Up});
                } else if ((i->x == next->x - 1) && (i->y == next->y)) {
                    _map.push_back(PathCell{i->x, i->y, Direction::Left});
                } else if ((i->x == next->x) && (i->y == next->y - 1)) {
                    _map.push_back(PathCell{i->x, i->y, Direction::Down});
                } else {
                    throw new path_error("This is not a correct path, some cells are disconnected");
                }
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
        if (_currentWave->_enemyNumber > 0) {
            if (_spawnCount >= _currentWave->_startAfter && (_spawnCount - _currentWave->_startAfter) % _currentWave->_enemyIntervalTick == 0) {
                _enemies.push_back(SP<Enemy>(new Enemy(_map, _currentWave->_health, _currentWave->_speed, _currentWave->_attackDamage)));
                _currentWave->_enemyNumber--;
            }
        } else {
            _currentWave++;
            _spawnCount = 0;
        }
    }
}

void Game::attack() {
    for (MyList<DeepPtr<Turret>>::iterator i = _turrets.begin(); i != _turrets.end(); ++i) {
        (*i)->attack();
    }
}

void Game::checkDeadEnemies() {
    for (vector<SP<Enemy>>::iterator i = _enemies.begin(); i != _enemies.end(); ++i) {
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
