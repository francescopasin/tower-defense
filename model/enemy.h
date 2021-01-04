#ifndef MODEL_ENEMY_H_
#define MODEL_ENEMY_H_

#include <vector>

#include "model/pathcell.h"
#include "model/position.h"

using std::vector;

namespace model {

class Enemy {
   private:
    int _currentCell;
    float _cellPosition;
    float _health;
    int _speed;
    vector<PathCell> _path;

   public:
    Enemy(const vector<PathCell>& path, float _health, float _speed);

    void receiveAttack(float damage);
    void move();

    Position getPosition() const;
    float getCellPosition() const;
    float getHealth() const;
};

}  // namespace model

#endif