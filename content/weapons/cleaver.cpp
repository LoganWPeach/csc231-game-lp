#include "cleaver.h"
#include "hit.h"
#include "engine.h"
#include "events.h"
#include "swing.h"
#include "thrust.h"

Cleaver::Cleaver(int damage)
    :Weapon{"cleaver", damage} {}

void Cleaver::use(Engine& engine, Entity& attacker, Entity& defender) {
    Vec direction = defender.get_position() - attacker.get_position();
    std::shared_ptr<Event> thrust = engine.events.create_event<Thrust>(sprite, direction);
    thrust->add_next(Hit(defender, damage));
}