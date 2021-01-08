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
    const vector<PathCell> _path;

   public:
    Enemy(const vector<PathCell>& path, float _health, U_INT _speed);

    void receiveAttack(float damage);
    void move();

    Position getPosition() const;
    float getCellPosition() const;
    float getHealth() const;
};

}  // namespace model

#endif