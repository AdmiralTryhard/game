#pragma once

#include "action.h"
#include "vec.h"
//moves in specified direction
class OpenDoor : public Action {
public:
    OpenDoor(Vec direction);
    Result perform(Engine& engine) override;
};