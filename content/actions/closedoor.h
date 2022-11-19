#pragma once

#include "action.h"

//moves in specified direction
class CloseDoor : public Action {
public:
    Result perform(Engine& engine) override;

};