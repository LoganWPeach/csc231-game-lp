#include "heros.h"
#include "entity.h"
#include "engine.h"
#include "rest.h"
#include "move.h"

namespace Heros {

    void make_knight(std::shared_ptr<Entity> entity) {
        entity->set_sprite("knight");
        entity->behavior = behavior;
    }

    std::unique_ptr<Action> behavior(Engine& engine, Entity&) {
        std::string key = engine.input.get_last_keypress();
        if (key == "R") {
            return std::make_unique<Rest>();
        }
        if ((key == "W") || (key == "Up")) {
            return std::make_unique<Move>(Vec{0,1});
        }
        return nullptr;
    }
}
