#include "move.h"
#include "actor.h"
#include "engine.h"
#include "tile.h"
#include "dungeon.h"
#include <iostream>
Move::Move(Vec direction) : direction{direction}{

}

Result Move::perform(Engine& engine){
    Vec position = actor->get_position();
    Vec new_position = position + direction;
    if(!engine.dungeon.tiles(new_position).is_wall() || 
    (engine.dungeon.tiles(new_position).is_door() && engine.dungeon.doors.at(new_position).is_open())){
        actor->move_to(new_position);
        actor->change_direction(direction);    
        std::cout << "You successfully moved " + '\n';
        return success();
    }
    else if(engine.dungeon.tiles(new_position).is_door() && !engine.dungeon.doors.at(new_position).is_open()){

        return failure();
        }
    else{
        return failure();
    }
    }
