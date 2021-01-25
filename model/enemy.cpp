#include "model/enemy.h"

namespace model {

Enemy::Enemy(const vector<PathCell>& path, float health, U_INT speed, float attackDamage)
    : _currentCell(0),
      _cellPosition(0),
      _health(health),
      _speed(speed),
      _attackDamage(attackDamage),
      _path(path) {}

void Enemy::receiveAttack(float damage) {
    _health -= damage;
}

float Enemy::move() {
    _cellPosition += 100 / static_cast<float>(_speed);

    if (_cellPosition >= 99) {
        _cellPosition = 0;
        _currentCell++;
    }

    // Check if last cell, then return the damage
    if (_currentCell == static_cast<int>(_path.size())) {
        return _attackDamage;
    }
    return 0;
}

PathCell Enemy::getCurrentCell() const {
    return _path[_currentCell];
}

float Enemy::getCellPosition() const {
    return _cellPosition;
}

float Enemy::getHealth() const {
    return _health;
}

}  // namespace model
