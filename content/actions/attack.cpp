#include "attack.h"
#include "actor.h"


Attack::Attack(Actor& defender) : defender{defender} {

}

Result Attack::perform(Engine&){
    actor->attack(defender);
    return success();
}