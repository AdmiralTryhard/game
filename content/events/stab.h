#pragma once

#include "event.h"
#include "actor.h"

class Actor;

class Stab : public Event {
public:
    Stab(Sprite& sprite, Vec direction, Actor& defender, int damage);

    void execute(Engine& engine) override;
    void when_done(Engine& engine) override;

private:
    Sprite& sprite;
    Sprite copy;
    Actor& defender;
    Vec direction;
    int damage;
    double starting_angle, delta;
};