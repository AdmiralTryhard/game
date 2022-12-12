#include "engine.h"
#include "heros.h"
#include "monsters.h"

int main() {
    std::string filename{"settings.txt"};
    Settings settings = read_settings(filename);
    Engine engine{settings};

    engine.create_hero(Heros::elf);

    MonsterType ogres = Monsters::ogre();
    MonsterType demons = Monsters::demon();
    for(int i = 0; i <= 30; ++i){
        MonsterType goblins = Monsters::goblin();
        engine.create_monster(goblins);
    }
    for(int i = 0; i <= 10; ++i){
        MonsterType demons = Monsters::demon();
        engine.create_monster(demons);
    }
    for(int i = 0; i <= 5; ++i){
        MonsterType ogres = Monsters::ogre();
        engine.create_monster(ogres);
   
    }
    engine.run();
}
