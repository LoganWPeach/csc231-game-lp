#include "bigsword.h"
#include "hit.h"
#include "engine.h"
#include "events.h"
#include "swing.h"
#include "thrust.h"

Bigsword::Bigsword(int damage)
    :Weapon{"sword_big", damage} {}

void Bigsword::use(Engine& engine, Entity& attacker, Entity& defender) {
    Vec direction = defender.get_position() - attacker.get_position();
    std::shared_ptr<Event> swing = engine.events.create_event<Swing>(sprite, direction);
    swing->add_next(Hit(defender, damage));
}