#include "move.h"
#include "entity.h"
#include "tile.h"
#include "dungeon.h"
#include "engine.h"
#include "opendoor.h"
#include "rest.h"

Result Move::perform(Engine& engine, std::shared_ptr<Entity> entity) {
    entity->change_direction(direction);
    Vec location = entity->get_position() + direction;
    Tile locationtile = engine.dungeon.get_tile(location);
    if (locationtile.is_wall()) {
        return failure();
    }
    if (locationtile.has_entity()) {
        return alternative(Rest());
    }
    else if (locationtile.has_door() && !locationtile.door->is_open()) {
        return alternative(Opendoor(direction));
    }
    else {
        entity->move_to(location);
        return success();
    }

}

Move::Move(Vec direction) : direction{direction} {}
