#include "sword.h"
#include "engine.h"
#include "hit.h"
#include "randomness.h"
#include "swing.h"
Sword::Sword(int damage) :Weapon{"sword", damage}{

}

void Sword::use(Engine& engine, Actor& attacker, Actor& defender){
    Vec direction = defender.get_position() - attacker.get_position();
    if(probability(50 + attacker.speed * 4)){ //faster characters are more likely to hit.
        engine.events.add(Swing{sprite, direction, defender, damage + attacker.health / 4}); // beefier characters will have less speed and hit harder.
    }
    else{
        engine.events.add(Swing{sprite, direction, defender, 0, }); //even misses show the swing animation so you know
    }
}