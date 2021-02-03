#ifndef MODEL_PATHCELL_H_
#define MODEL_PATHCELL_H_

#include "app/shortcuts.h"
#include "model/direction.h"
#include "model/position.h"

namespace model {

struct PathCell {
    U_INT x;
    U_INT y;
    Direction from;
    Direction to;

    Position getPosition() const {
        Position p{x, y};
        return p;
    }

    bool operator==(const PathCell& other) const {
        return x == other.getPosition().x && y == other.getPosition().y;
    }
};

}  // namespace model

#endif
