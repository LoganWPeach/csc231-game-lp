#include "hit.h"
#include "die.h"

Hit::Hit(Entity& entity, int damage)
    :entity{entity}, damage{damage} {}

void Hit::execute(Engine& engine) {
    entity.take_damage(damage);
}
void Hit::when_done(Engine&) {
    if (!entity.is_alive()) {
        add_next(Die{entity});
    }
}