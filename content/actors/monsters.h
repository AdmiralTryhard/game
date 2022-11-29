#pragma once

#include "monstertype.h"
#include "none.h"
#include "engine.h"

namespace Monsters {
    std::unique_ptr<Action> default_behavior(Engine& engine, Monster& me);

    MonsterType goblin();
    MonsterType ogre();
    MonsterType demon();
    constexpr int default_speed{8};
    MonsterType goblin() { 
    int health = 2; 
    return {"goblin", default_speed, health, std::make_shared<None>(), default_behavior}; 
    }
    MonsterType ogre() { 
    int health = 8; 
    return {"goblin", default_speed, health, std::make_shared<None>(), default_behavior};  
    }
    MonsterType demon() { 
    int health = 10; 
    return {"goblin", default_speed, health, std::make_shared<None>(), default_behavior}; 
    }
}
