#include "knife.h"
#include "engine.h"
#include "hit.h"
#include "randomness.h"
Knife::Knife(int damage) :Weapon{"knife", damage}{

}

void Knife::use(Engine& engine, Actor& attacker, Actor& defender){
    if(probability(50 + attacker.speed * 8)){ //faster characters are more likely to hit.
        engine.events.add(Hit{defender, damage + attacker.health / 8}); // beefier characters will have less speed and hit harder.
    }
}