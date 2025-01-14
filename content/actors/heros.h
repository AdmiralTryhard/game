#pragma once

#include "herotype.h"
#include "none.h"
#include "move.h"
#include "closedoor.h"
#include "rest.h"
#include "sword.h"
#include "spear.h"

namespace Heros {
    const std::unordered_map<std::string, Reaction> key_bindings = {
        {"Left", []() {
            return std::make_unique<Move>(Vec{-1, 0});
        }},
        {"Right", []() {
            return std::make_unique<Move>(Vec{1, 0});
        }},
        {"Up", [](
            
        ) {
            return std::make_unique<Move>(Vec{0, 1});
        }},
        {"Down", [](){
            return std::make_unique<Move>(Vec{0, -1});
        }},
        {"R", [](){
            return std::make_unique<Rest>();
        }},
        {"C", [](){
            return std::make_unique<CloseDoor>();
        }}
    };       
    constexpr int default_speed{8};
    const HeroType nobody{"none", default_speed, 1, std::make_shared<None>(), {}};
    const HeroType elf{"elf", default_speed, 20, std::make_shared<Spear>(3), key_bindings};


}
