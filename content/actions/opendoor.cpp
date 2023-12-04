#include "opendoor.h"

#include "audioevent.h"
#include "engine.h"
#include "entity.h"
#include "updatefov.h"

Result Opendoor::perform(Engine& engine, std::shared_ptr<Entity> entity) {
    Vec position = entity->get_position();
    position += direction;
    Tile& tile = engine.dungeon.get_tile(position);
    tile.door->open();
    engine.events.create_event<UpdateFOV>();
    if (tile.is_visible()) {
        engine.events.create_event<AudioEvent>("door-open");
    }
    return success();
}

Opendoor::Opendoor(Vec direction) : direction{direction} {}