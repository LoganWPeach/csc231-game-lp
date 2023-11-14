#include "opendoor.h"
#include "entity.h"
#include "engine.h"
#include "updatefov.h"

Result Opendoor::perform(Engine& engine, std::shared_ptr<Entity> entity) {
    Vec position = entity->get_position();
    position += direction;
    Tile& tile = engine.dungeon.get_tile(position);
    tile.door->open();
    engine.events.create_event<UpdateFOV>();
    return success();
}

Opendoor::Opendoor(Vec direction) : direction{direction} {}