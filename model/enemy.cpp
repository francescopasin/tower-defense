#include "enemy.h"

namespace model {

Enemy::Enemy(std::vector<PathCell> path, float health, float speed) : _currentCell(0),
                                                                      _cellPosition(0),
                                                                      _health(health),
                                                                      _speed(speed),
                                                                      _path(path) {}

void Enemy::receiveAttack(float damage) {
    _health -= damage;

    if (_health <= 0) {
        // TODO: remove enemy from Game's enemies list and delete this
    }
}

void Enemy::move() {
    _cellPosition += 100 / _speed;

    if (_cellPosition >= 99) {
        _cellPosition = 0;
        _currentCell++;
    }

    // Check if last cell
    if (_currentCell == static_cast<int>(_path.size())) {
        // TODO: remove enemy from Game's enemies list and delete this
        // TODO: remove life points from Game
    }
}

Position Enemy::getPosition() const {
    return _path[_currentCell].getPosition();
}

float Enemy::getCellPosition() const {
    return _cellPosition;
}

float Enemy::getHealth() const {
    return _health;
}

}  // namespace model
