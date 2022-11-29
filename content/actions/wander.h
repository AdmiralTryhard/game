#pragma once

#include "action.h"


class Wander: public Action{
public:
Result perform(Engine& engine) override;

};