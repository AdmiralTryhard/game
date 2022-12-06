#include "sword.h"
#include "engine.h"
#include "hit.h"
#include "randomness.h"
Sword::Sword(int damage) :Weapon{"sword", damage}{

}

void Sword::use(Engine& engine, Actor& attacker, Actor& defender){
    if(probability(50 + attacker.speed * 4)){ //faster characters are more likely to hit.
        engine.events.add(Hit{defender, damage + attacker.health / 4}); // beefier characters will have less speed and hit harder.
    }
}