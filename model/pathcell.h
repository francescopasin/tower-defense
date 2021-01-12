#ifndef MODEL_PATHCELL_H_
#define MODEL_PATHCELL_H_

#define U_INT unsigned short int

#include "model/direction.h"
#include "model/position.h"

namespace model {

struct PathCell {
    U_INT x;
    U_INT y;
    Direction d;

    Position getPosition() const {
        Position p{x, y};
        return p;
    }
};

}  // namespace model

#endif