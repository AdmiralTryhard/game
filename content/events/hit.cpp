#include "hit.h"
#include "actor.h"
#include "engine.h"
#include "die.h"

Hit::Hit(Actor& actor, int damage, int frame_count) :
actor{actor}, 
damage{damage},
Event{frame_count}{

}

void Hit::execute(Engine&){
 //delays the event so that it can run in parallel to other events
}

void Hit::when_done(Engine& engine){
    actor.take_damage(damage);
    if(actor.health <= 0){
       engine.events.add(Die{actor});
    }
}