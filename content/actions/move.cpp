#include "move.h"
#include "entity.h"
#include "tile.h"
#include "dungeon.h"
#include "engine.h"

Result Move::perform(Engine& engine, std::shared_ptr<Entity> entity) {
    entity->change_direction(direction);
    Vec location = entity->get_position() + direction;
    Tile locationtile = engine.dungeon.get_tile(location);
    if (locationtile.is_wall()) {
        return failure();
    }
    else {
        entity->move_to(location);
        return success();
    }

}

Move::Move(Vec direction) : direction{direction} {}
