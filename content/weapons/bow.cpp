#include "bow.h"
#include "hit.h"
#include "engine.h"

Bow::Bow(int damage)
    :Weapon{"bow", damage} {}

void Bow::use(Engine& engine, Entity&, Entity& defender) {
    engine.events.create_event<Hit>(defender, damage);
}