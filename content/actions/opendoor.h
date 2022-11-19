#pragma once

#include "action.h"
#include "vec.h"


class OpenDoor : public Action {
public:
    OpenDoor(Vec direction);
    Result perform(Engine& engine) override;

private:
    Vec direction;
};