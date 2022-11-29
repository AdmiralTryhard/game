#pragma once

#include "monstertype.h"
#include "none.h"
#include "action.h"
#include "engine.h"

namespace Monsters {
    std::unique_ptr<Action> default_behavior(Engine& engine, Monster& me);

    MonsterType goblin();
    MonsterType ogre();
    MonsterType demon();
    constexpr int default_speed{8};



}
