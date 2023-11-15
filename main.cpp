#include "engine.h"
#include "heros.h"
#include "monsters.h"
#include <iostream>
#include "entity.h"

int main() {
    try {
        Settings settings{"settings.txt"};
        Engine engine{settings};

        std::shared_ptr<Entity> hero = engine.create_hero();
        Heros::make_knight(hero);

        for (int i = 0; i < 10; ++i) {
            std::shared_ptr<Entity> monster = engine.create_monster();
            Monsters::make_orc(monster);
        }

        engine.run();
    }
    catch (std::exception& e) {
        std::cout << e.what() << '\n';
    }
}
