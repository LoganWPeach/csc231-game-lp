#include "move.h"
#include "entity.h"
#include "tile.h"

Result Move::perform(Engine& engine, std::shared_ptr<Entity> entity) {
    Vec location = entity->get_position() + direction;
    entity->move_to(location);
    entity->change_direction(direction);
    return success();
}

Move::Move(Vec direction) : direction{direction} {}
