#ifndef MODEL_WAVE_H_
#define MODEL_WAVE_H_

namespace model {

#define U_INT unsigned short int

struct Wave {
    float enemiesHealth;
    U_INT enemiesSpeed;
    float enemiesAttackDamage;
    U_INT enemiesNumber;
    U_INT enemiesIntervalTick;
    U_INT startsAfter;
};

}  // namespace model

#endif
