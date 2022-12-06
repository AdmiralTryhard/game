#include "monsters.h"
#include "monster.h"
#include "engine.h"
#include "move.h"
#include "wander.h"
#include "rest.h"
#include "randomness.h"
#include "sword.h"




    MonsterType Monsters::goblin() { 
        int health = 2; 
        return {"goblin", default_speed, health, std::make_shared<Sword>(3), default_behavior}; 
    }
    MonsterType Monsters::ogre() { 
        int health = 8; 
        return {"ogre", default_speed, health, std::make_shared<Sword>(3), default_behavior};  
    }
    MonsterType Monsters::demon() { 
        int health = 10; 
        return {"demon", default_speed, health, std::make_shared<Sword>(3), default_behavior}; 
    }
std::unique_ptr<Action> Monsters::default_behavior(Engine& engine, Monster& me){
    //pursue hero if seen
        if(me.is_visible() && engine.hero){
            Vec from = me.get_position();
            Vec to = engine.hero->get_position();
            std::vector<Vec> path = engine.dungeon.calculate_path(from, to);
            if(path.size() > 1) { //monster is not at the hero
                Vec direction = path.at(1) - path.at(0);
                return std::make_unique<Move>(direction);
            }
        }
        //Monster does not see hero
        if (probability(66)){
            return std::make_unique<Wander>();
        }
        else {
            return std::make_unique<Rest>();
        }
}
