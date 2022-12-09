#include "swing.h"
#include "hit.h"
#include "engine.h"
#include "event.h"
#include <cmath>
constexpr int duration = 5;
Swing::Swing(Sprite& sprite, Vec direction, Actor& defender, int damage) 
    :Event{duration},
    sprite{sprite},
    copy{sprite},
    defender{defender}, 
    damage{damage} {
    //set starting angle
    //set rotation direction via delta.
    if(direction == Vec{1, 0}){
        starting_angle = 0;
        delta = 135.0 / (duration - 1);
    }
    else if(direction == Vec{-1, 0}){
        starting_angle = 0;
        delta = -135.0 / (duration - 1);
    }
    else if(direction == Vec{0, 1}){
        sprite.shift.y -= 12;
        double sign = std::copysign(1.0, starting_angle);
        starting_angle = -75 * sign;
        delta = 90.0 / (duration - 1) * sign;
    }
    else{
        sprite.shift.x = 0;
        double sign = std::copysign(1.0, starting_angle);
        starting_angle = 135 * sign;
        delta = 90.0 / (duration - 1) * sign;
    }
}

void Swing::execute(Engine&){
    sprite.angle = starting_angle + (delta * frame_count);
}

void Swing::when_done(Engine& engine){
    sprite = copy;
    engine.events.add(Hit{defender, damage});
}