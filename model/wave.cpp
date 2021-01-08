#include "wave.h"

namespace model {
Wave::Wave(float health, U_INT speed, U_INT enemyNumber, U_INT enemyIntervalTick, U_INT startAfter) : _health(health), _speed(speed), _enemyNumber(enemyNumber), _enemyIntervalTick(enemyIntervalTick), _startAfter(startAfter) {}

}  // namespace model