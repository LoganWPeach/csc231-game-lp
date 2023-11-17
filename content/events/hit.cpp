#include "hit.h"
#include "die.h"

void Hit::execute(Engine& engine) {
    entity.take_damage(damage);
}
void Hit::when_done(Engine&) {
    if (!entity.is_alive()) {
        add_next(Die{entity});
    }
}