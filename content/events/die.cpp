#include "die.h"

Die::Die(Entity& entity)
    :entity{entity} {}
void Die::execute(Engine& engine) {
    engine.dungeon.remove_entity(entity.get_position());
}
