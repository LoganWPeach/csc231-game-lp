#include "bow.h"
#include "hit.h"
#include "engine.h"
#include "events.h"
#include "swing.h"
#include "thrust.h"

Bow::Bow(int damage)
    :Weapon{"bow", damage} {}

void Bow::use(Engine& engine, Entity& attacker, Entity& defender) {
    Vec direction = defender.get_position() - attacker.get_position();
    std::shared_ptr<Event> swing = engine.events.create_event<Swing>(sprite, direction);
    engine.events.create_event<Hit>(defender, damage);
    swing->add_next(Hit(defender, damage));
}