#include "spear.h"
#include "engine.h"
#include "hit.h"
#include "stab.h"
#include "randomness.h"
#include "vec.h"
Spear::Spear(int damage) :Weapon{"spear", damage}{

}

void Spear::use(Engine& engine, Actor& attacker, Actor& defender){
    Vec direction = defender.get_position() - attacker.get_position();
    if(probability(50 + attacker.speed * 4)){ //faster characters are more likely to hit.
        engine.events.add(Stab{sprite, direction, defender, damage + attacker.health / 4}); // beefier characters will have less speed and hit harder.
        Actor* unlucky_victim = engine.dungeon.tiles(defender.get_position() + direction).actor; //guy behind the person about to be speared
        if(unlucky_victim != nullptr){ //purposefully has 100% hit rate if it goes through, be it for better or worse.
            engine.events.add(Hit{*unlucky_victim, damage + attacker.health / 4, 5});
        }
    }
    else{
        engine.events.add(Stab{sprite, direction, defender, 0}); // still stab, but no damage
    }
}