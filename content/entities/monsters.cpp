#include "monsters.h"

#include "bigsword.h"
#include "bow.h"
#include "cleaver.h"
#include "engine.h"
#include "entity.h"
#include "knife.h"
#include "move.h"
#include "randomness.h"
#include "rest.h"
#include "shoot.h"
#include "wander.h"
#include <cmath>

namespace Monsters {
    void make_orc(std::shared_ptr<Entity> monster) {
        monster->set_sprite("orc");
        monster->set_max_health(10);
        monster->behavior = behavior;
        monster->set_weapon(std::make_shared<Cleaver>(5));
    }
    void make_orc_ranged(std::shared_ptr<Entity> monster) {
        monster->set_sprite("orc_masked");
        monster->set_max_health(10);
        monster->behavior = behavior2;
        monster->set_weapon(std::make_shared<Bow>(5));
    }
    void make_skeleton(std::shared_ptr<Entity> monster) {
        monster->set_sprite("skeleton");
        monster->set_max_health(5);
        monster->behavior = behavior;
        monster->set_weapon(std::make_shared<Knife>(2));
    }
    void make_demon(std::shared_ptr<Entity> monster) {
        monster->set_sprite("demon");
        monster->set_max_health(40);
        monster->behavior = behavior;
        monster->set_weapon(std::make_shared<Bigsword>(12));
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
    std::unique_ptr<Action> behavior2(Engine& engine, Entity& entity) {
        // if visible to hero, see if vertically or horizonally lined up
        if (engine.hero && entity.is_visible()) {
            std::vector<Vec> path = engine.dungeon.calculate_path(entity.get_position(), engine.hero->get_position());
            Vec direction{};
            if (path.size() > 1) {
                direction = path.at(1) - path.at(0);
            }
            // Shoot
            if ((entity.get_position().x == engine.hero->get_position().x) || (entity.get_position().y == engine.hero->get_position().y)) {
                return std::make_unique<Shoot>(direction);
            }
            // Vertically/Horizontally Line Up
            else {
                // Find distances across different axis
                int ax = abs((engine.hero->get_position().x - entity.get_position().x));
                int ay = abs((engine.hero->get_position().y - entity.get_position().y));
                Vec px = coordinate(Vec(engine.hero->get_position().x - entity.get_position().x, 0));
                Vec py = coordinate(Vec(0, engine.hero->get_position().y - entity.get_position().y));
                Tile tilecheck{};
                if (ax > ay) {
                    tilecheck = engine.dungeon.get_tile(entity.get_position() + py);
                    if (tilecheck.has_entity() || tilecheck.is_wall()) {
                        return std::make_unique<Move>(direction);
                    }
                    else {
                        return std::make_unique<Move>(py);
                    }
                }
                if (ay > ax) {
                    tilecheck = engine.dungeon.get_tile(entity.get_position() + px);
                    if (tilecheck.has_entity() || tilecheck.is_wall()) {
                        return std::make_unique<Move>(direction);
                    }
                    else {
                        return std::make_unique<Move>(px);
                    }
                }
                if (ax == ay) {
                    return std::make_unique<Move>(direction);
                }
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
