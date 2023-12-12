#include "heros.h"
#include "castlightning.h"
#include "closedoor.h"
#include "engine.h"
#include "entity.h"
#include "move.h"
#include "rest.h"
#include "shoot.h"
#include "sword.h"

namespace Heros {

    void make_knight(std::shared_ptr<Entity> entity) {
        entity->set_sprite("knight");
        entity->set_max_health(100);
        entity->behavior = behavior;
        entity->set_weapon(std::make_shared<Sword>(10));
    }

    std::unique_ptr<Action> behavior(Engine& engine, Entity& entity) {
        std::string key = engine.input.get_last_keypress();
        if (key == "R") {
            return std::make_unique<Rest>();
        }
        if ((key == "W") || (key == "Up")) {
            return std::make_unique<Move>(Vec{0,1});
        }
        if ((key == "A") || (key == "Left")) {
            return std::make_unique<Move>(Vec{-1,0});
        }
        if ((key == "S") || (key == "Down")) {
            return std::make_unique<Move>(Vec{0,-1});
        }
        if ((key == "D") || (key == "Right")) {
            return std::make_unique<Move>(Vec{1,0});
        }
        if (key == "C") {
            return std::make_unique<Closedoor>();
        }
        if (key == "L") {
            return std::make_unique<CastLightning>();
        }
        if (key == "P") {
            return std::make_unique<Shoot>(entity.get_direction());
        }
        return nullptr;
    }
}
