#include "rest.h"
#include "actor.h"
//heals 1 hp unless above 1/2 max_health
Result Rest::perform(Engine&) {
    if(actor->health <= actor->max_health/2){
        actor->heal(1);
    }
    return success();
}
