#include "move.h"
#include "actor.h"
#include "engine.h"
#include "tile.h"
#include "dungeon.h"
#include "opendoor.h"
#include "rest.h"


Move::Move(Vec direction) : direction{direction}{

}

Result Move::perform(Engine& engine){
    Vec position = actor->get_position();
    Vec new_position = position + direction;
    bool is_wall = engine.dungeon.tiles(new_position).is_wall();
    bool is_door = engine.dungeon.tiles(new_position).is_door();
    if(is_wall){
        return failure();
    }
    if(is_door){
        Door& door = engine.dungeon.doors.at(new_position);
        if(door.is_open()){
            actor->move_to(new_position);
            actor->change_direction(direction);
            return success();
        }
        else {
            return alternative(OpenDoor{direction});
        }
    }
    else { // only floor and future enemies
        if(engine.dungeon.tiles(new_position).actor == nullptr) {
            actor->move_to(new_position);
            return success();
        }
        else{
        actor->change_direction(direction);
        return alternative(Rest{}); //will be replaced with attacking once I figure this out
        }
    }
}

