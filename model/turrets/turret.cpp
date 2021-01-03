#include "model/turrets/turret.h"

namespace model {

Turret::Turret(const Position& position, const SP<vector<SP<Enemy>>>& enemies, U_INT attackRadius) : _position(position),
                                                                                                     _enemies(enemies),
                                                                                                     _attackRadius(attackRadius) {}

vector<SP<Enemy>> Turret::getEnemiesInRadius() const {
    vector<SP<Enemy>> enemies = vector<SP<Enemy>>();

    for (auto& enemy : *_enemies) {
        // Loop radius x
        for (int i = _position.x - _attackRadius; i <= _position.x + _attackRadius; i++) {
            // Loop radius y
            for (int j = _position.y - _attackRadius; j <= _position.y + _attackRadius; j++) {
                if (enemy->getPosition().x == i && enemy->getPosition().y == j) {
                    enemies.push_back(enemy);
                }
            }
        }
    }

    return enemies;
}

Position Turret::getPosition() const {
    return _position;
}

}  // namespace model
