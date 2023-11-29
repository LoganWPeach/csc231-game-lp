#include "bigsword.h"
#include "cleaver.h"
#include "monsters.h"
#include "engine.h"
#include "entity.h"
#include "rest.h"
#include "move.h"
#include "wander.h"
#include "randomness.h"

namespace Monsters {
    void make_orc(std::shared_ptr<Entity> monster) {
        monster->set_sprite("orc");
        monster->set_max_health(10);
        monster->behavior = behavior;
        monster->set_weapon(std::make_shared<Cleaver>(5));
    }
    void make_skeleton(std::shared_ptr<Entity> monster) {
        monster->set_sprite("skeleton");
        monster->set_max_health(5);
        monster->behavior = behavior;
    }
    void make_demon(std::shared_ptr<Entity> monster) {
        monster->set_sprite("demon");
        monster->set_max_health(50);
        monster->behavior = behavior;
        monster->set_weapon(std::make_shared<Bigsword>(15));
    }
    std::unique_ptr<Action> behavior(Engine& engine, Entity& entity) {
        // if visible to hero, calculate path and move towards hero
        if (engine.hero && entity.is_visible()) {
            std::vector<Vec> path = engine.dungeon.calculate_path(entity.get_position(), engine.hero->get_position());
            if (path.size() > 1) {
                Vec direction = path.at(1) - path.at(0);
                return std::make_unique<Move>(direction);
            }
        }
        // if Hero can't see monster

        if (probability(70)) {
            return std::make_unique<Wander>();
        }
        else {
            return std::make_unique<Rest>();
        }
    }
}
