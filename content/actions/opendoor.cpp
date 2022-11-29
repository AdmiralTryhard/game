#include "opendoor.h"
#include "engine.h"
#include "door.h"
#include "dungeon.h"
#include "actor.h"
#include "events.h"
#include "updatefov.h"

OpenDoor::OpenDoor(Vec direction) : direction{direction}{
}


Result OpenDoor::perform(Engine& engine){
    Door& door = engine.dungeon.doors.at(actor->get_position() + direction);
    door.open();
    engine.events.add(UpdateFOV{});
    return success();

}