#pragma once

#include "action.h"
class Actor;
class Attack : public Action {
public:
    Attack(Actor& defender);
    Result perform(Engine& engine);

private: 
    Actor& defender;
};