#ifndef MODEL_POSITION_H_
#define MODEL_POSITION_H_

#define U_INT unsigned short int

namespace model {

struct Position {
    U_INT x;
    U_INT y;

    bool operator==(const Position& other) {
        return x == other.x && y == other.y;
    }
};

}  // namespace model

#endif