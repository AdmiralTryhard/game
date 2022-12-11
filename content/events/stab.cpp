#include "stab.h"
#include "hit.h"
#include "engine.h"
#include <cmath>

constexpr int duration = 5;
Stab::Stab(Sprite& sprite, Vec direction, Actor& defender, int damage)
:Event{duration},
sprite{sprite},
copy{sprite},
direction{direction},
defender{defender}, 
damage{damage}{
delta = 15;


    if(direction == Vec{1, 0}){
        starting_angle = 90;
    }
    else if(direction == Vec{-1, 0}){
        starting_angle = -90;
    }
    else if(direction == Vec{0, 1}){
        sprite.shift.y -= 12; //image coordinates means this is up
        double sign = std::copysign(1.0, starting_angle);
        sprite.shift.x += 10 * sign;
        starting_angle = 0;
    }
    else{
        sprite.shift.y += 12; //likewise this means down
        double sign = std::copysign(1.0, starting_angle);
        sprite.shift.x += 10 * sign;
        starting_angle = 180;
    }

}

    void Stab::execute(Engine&){
    if(direction == Vec{1, 0}){
        sprite.shift.x += delta/duration;
    }
    else if(direction == Vec{-1, 0}){
        sprite.shift.x -= delta/duration;
    }
    else if(direction == Vec{0, 1}){
        sprite.shift.y -= delta/duration;
    }
    else{
        sprite.shift.y += delta/duration;
    }    
}

void Stab::when_done(Engine& engine){
    sprite = copy;
    engine.events.add(Hit{defender, damage});
}