#include "model/turret.h"

namespace model {

Turret::Turret(const Position& position, const SP<vector<SP<Enemy>>>& enemies) : _position(position),
                                                                                 _enemies(enemies) {}

Position Turret::getPosition() const {
    return _position;
}

}  // namespace model
