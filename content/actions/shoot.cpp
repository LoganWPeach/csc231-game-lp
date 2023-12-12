#include "arrow.h"
#include "door.h"
#include "engine.h"
#include "shoot.h"
#include "tile.h"
#include "weapon.h"

Shoot::Shoot(Vec direction) : direction{direction} {}

Result Shoot::perform(Engine& engine, std::shared_ptr<Entity> entity) {
    Vec curr = entity->get_position();
    curr += direction;
    Tile& t = engine.dungeon.get_tile(curr);
    while (!t.is_wall() && !t.has_entity() && !(t.has_door() && !t.door->is_open())) {
        curr += direction;
        t = engine.dungeon.get_tile(curr);
    }
    Vec dis = curr - entity->get_position();

    // engine.events.create_event<Arrow>(engine.dungeon.get_tile(entity->get_position()), dis);
    if (t.has_entity()) {
        entity->get_weapon()->use(engine, *entity, *t.entity);
    }
    return success();
}
