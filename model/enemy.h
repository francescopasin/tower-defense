#ifndef MODEL_ENEMY_H_
#define MODEL_ENEMY_H_

#include <vector>

#include "model/pathcell.h"
#include "model/position.h"

using std::vector;

#define U_INT unsigned short int

namespace model {

class Enemy {
   private:
    U_INT _currentCell;
    float _cellPosition;
    float _health;
    U_INT _speed;
    float _attackDamage;
    const vector<PathCell> _path;
    U_INT _reward;
    float _initialHealt;

   public:
    Enemy(const vector<PathCell>& path, float _health, U_INT _speed, float _attackDamage, U_INT reward);

    void receiveAttack(float damage);
    float move();

    PathCell getCurrentCell() const;
    float getCellPosition() const;
    float getHealth() const;
    U_INT getReward() const;
    float getInitialHealt() const;
};

}  // namespace model

#endif