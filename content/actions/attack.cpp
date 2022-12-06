#include "attack.h"
#include "engine.h"
#include "actor.h"

Attack::Attack(Actor& defender) :defender{defender} {

}

Result perform(Engine&){
    actor->attack(defender);
    return success();
}
