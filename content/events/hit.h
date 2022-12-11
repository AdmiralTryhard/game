#pragma once

#include "event.h"

//forward declaration
class Actor;

class Hit : public Event {
public:
    Hit(Actor& actor, int damage, int frame_count = 1);
    void execute(Engine& engine) override;
    void when_done(Engine& engine) override;

private:
    Actor& actor;
    int damage;
};