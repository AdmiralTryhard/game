#include "engine.h"
#include "heros.h"
#include "monsters.h"

int main() {
    std::string filename{"settings.txt"};
    Settings settings = read_settings(filename);
    Engine engine{settings};

    engine.create_hero(Heros::elf);

    MonsterType goblins = Monsters::goblin();
    MonsterType ogres = Monsters::ogre();
    MonsterType demons = Monsters::demon();
    for(int i = 0; i <= 20; ++i){
        engine.create_monster(goblins);
    }
    engine.create_monster(demons);
    engine.create_monster(ogres);
    engine.run();
}
