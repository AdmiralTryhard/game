#include "spear.h"
#include "engine.h"
#include "hit.h"
#include "randomness.h"
#include "vec.h"
Spear::Spear(int damage) :Weapon{"spear", damage}{

}

void Spear::use(Engine& engine, Actor& attacker, Actor& defender){
    if(probability(50 + attacker.speed * 4)){ //faster characters are more likely to hit.
        engine.events.add(Hit{defender, damage + attacker.health / 4}); // beefier characters will have less speed and hit harder.
        Vec direction = defender.get_position() - attacker.get_position();
        Actor* unlucky_victim = engine.dungeon.tiles(defender.get_position() + direction).actor; //guy behind the person about to be speared
        if(unlucky_victim != nullptr){
            engine.events.add(Hit{*unlucky_victim, damage + attacker.health / 4});
        }
    }
}