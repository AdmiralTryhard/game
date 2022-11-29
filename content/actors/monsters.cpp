#include "monsters.h"
#include "monster.h"
#include "engine.h"
#include "move.h"
#include "wander.h"
#include "rest.h"
#include "randomness.h"

std::unique_ptr<Action> default_behavior(Engine& engine, Monster& me){
    //pursue hero if seen
    if(me.is_visible() && engine.hero){
        Vec from = me.get_position();
        Vec to = engine.hero->get_position();
        std::vector<Vec> path = engine.dungeon.calculate_path(from, to);

        if(path.size() > 1) {
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
