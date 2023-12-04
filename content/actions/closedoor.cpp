#include "closedoor.h"
#include "audioevent.h"
#include "engine.h"
#include "entity.h"
#include "updatefov.h"

Result Closedoor::perform(Engine& engine, std::shared_ptr<Entity> entity) {
    Vec position = entity->get_position();
    std::vector<Vec> neighbors = engine.dungeon.neighbors(position);
    bool closed_any_doors{false};
    for (Vec position : neighbors) {
        Tile& tile = engine.dungeon.get_tile(position);
        if (tile.has_door() && tile.door->is_open()) {
            tile.door->close();
            closed_any_doors = true;
            // Door& door = *tile.door; Asterisk is Pointer to object
            // door.close();
        }
    }
    if (closed_any_doors) {
        engine.events.create_event<UpdateFOV>();
        engine.events.create_event<AudioEvent>("door-close");
        return success();
    }
    else {
        return failure();
    }
}