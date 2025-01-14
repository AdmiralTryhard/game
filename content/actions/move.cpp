#include "move.h"
#include "actor.h"
#include "engine.h"
#include "tile.h"
#include "dungeon.h"
#include "opendoor.h"
#include "rest.h"
#include "attack.h"

Move::Move(Vec direction) : direction{direction}{

}

Result Move::perform(Engine& engine){
    Vec position = actor->get_position();
    Vec new_position = position + direction;
    bool is_wall = engine.dungeon.tiles(new_position).is_wall();
    bool is_door = engine.dungeon.tiles(new_position).is_door();
    actor->change_direction(direction); //always going to look where you tried to move
    if(is_wall){
        return failure();
    }
    if(is_door){
        Door& door = engine.dungeon.doors.at(new_position);
        if(!door.is_open()){
            return alternative(OpenDoor{direction});
        }
    }
    // only floor and future enemies
    if(engine.dungeon.tiles(new_position).actor == nullptr) {
        actor->move_to(new_position);
        return success();
    }
    Actor* possible_enemy = engine.dungeon.tiles(new_position).actor;
    if(possible_enemy->team == actor-> team){
        return alternative(Rest{}); //Prevents INTENTIONAL friendly fire.
    }

    return alternative(Attack{*possible_enemy}); 
}
    

