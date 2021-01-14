#ifndef MODEL_WAVE_H_
#define MODEL_WAVE_H_

namespace model {

#define U_INT unsigned short int

struct Wave {
    float _health;
    U_INT _speed;
    U_INT _enemyNumber;
    U_INT _enemyIntervalTick;
    U_INT _startAfter;
    float _attackDamage;
};

}  // namespace model

#endif
