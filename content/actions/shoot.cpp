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

    while (true) {
        Tile& tile = engine.dungeon.get_tile(curr);
        if (tile.is_wall() || tile.has_entity() || (tile.has_door() && !tile.door->is_open())) {
            break;
        }
        curr += direction;
    }

    Vec dis = curr - entity->get_position();
    engine.events.create_event<Arrow>(entity->get_position(), dis);
    Tile& tile = engine.dungeon.get_tile(curr);
    if (tile.has_entity()) {
        entity->get_weapon()->use(engine, *entity, *tile.entity);
    }
    return success();
}
