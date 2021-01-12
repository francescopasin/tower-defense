#include "Game.h"

namespace model {

Game::Game() : _tick(0), _currentWave(_waves.end()), _spawnCount(0), _currentState(State::Setup) {}

void Game::addTurret(Turret& turret) {  //? NO Const Turret&? da ragionare cosa fa deepptr in costruzione di copia
    _turrets.pushBack(&turret);
}

void Game::removeTurret(U_INT index) {
    _turrets.erase(index);
}

float Game::getCredit() const {
    return _credits;
}

void Game::toReady() {
    if (_map.size() > 0 && _waves.size() > 0)
        _currentState = State::Ready;
}

void Game::setMap(const vector<Position>& map) {
    if (_currentState == State::Setup) {
        auto it = std::unique(map.begin(), map.end());
        bool wasUnique = (it == map.end());
        if (wasUnique) {
            for (vector<Position>::const_iterator i = map.cbegin(); i != map.cend(); ++i) {
                vector<Position>::const_iterator next = i + 1;
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
                        //! ERROR "This is not a correct path, some cells are disconnected"
                    }
                }
            }
        } else {
            //! ERROR "This is not a correct path, you can't go through the same cell twice"
        }
    } else {
        //! ERROR "This game is already started, you can't set map now"
    }
    toReady();
}

void Game::addWave(const Wave& wave) {
    if (_currentState == State::Setup) {
        _waves.push_back(wave);
        if (_waves.size() == 1) {
            _currentWave = _waves.begin();
        }
    } else {
        //! ERROR "This game is already started, you can't set map now"
    }
    toReady();
}

void Game::moveEnemy() {
    for (vector<SP<Enemy>>::iterator i = _enemies.begin(); i != _enemies.end(); ++i) {
        _life -= (*i)->move();
    }
    if (_life <= 0)
        _currentState = State::Lost;
}

void Game::spawnEnemy() {
    if (_currentWave != _waves.end()) {
        _spawnCount++;
        if (_currentWave->_enemyNumber > 0) {
            if ((_spawnCount - _currentWave->_startAfter) % _currentWave->_enemyIntervalTick == 0 && _spawnCount >= _currentWave->_startAfter) {
                _enemies.push_back(SP<Enemy>(new Enemy(_map, _currentWave->_health, _currentWave->_speed)));
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
    if (_currentState == State::Ready || _currentState == State::InExecution) {
        _currentState = State::InExecution;
        _tick++;
        moveEnemy();
        spawnEnemy();
        attack();
        checkDeadEnemies();
        checkWon();
    }
    return _currentState;
}

}  // namespace model
