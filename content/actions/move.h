#pragma once

#include "action.h"
#include "vec.h"

//moves in specified direction
class Move : public Action {
public:
    Move(Vec direction);
    Result perform(Engine& engine) override;

private: 
    Vec direction;
};