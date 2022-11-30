#pragma once

#include "event.h"

class Actor;
class Die : public Event {
public:
    Die(Actor& actor);
    void execute(Engine& engine) override;


private:
    Actor& actor;
};