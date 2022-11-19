#include "closedoor.h"
#include "actor.h"
#include "engine.h"
#include <iostream>
Result CloseDoor::perform(Engine& engine){
    Vec position = actor->get_position();
    bool successful = false;
    std::vector<Vec> neighbors = engine.dungeon.neighbors(position);
    for(const Vec& neighbor : neighbors) {
        Tile& tile = engine.dungeon.tiles(neighbor);
        if (tile.is_door()){
            successful = true;
            Door& door = engine.dungeon.doors.at(neighbor);
            std::cout << "Door at " << neighbor << '\n';
            door.close();
        }
        else {
            std::cout << "Not door here at " << neighbor << '\n';
        }
    }
    if(successful){
        return success();
    }
    else {
        return failure();
    }
}