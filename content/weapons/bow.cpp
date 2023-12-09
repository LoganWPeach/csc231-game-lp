#include "bow.h"
#include "hit.h"
#include "engine.h"
#include "events.h"
#include "thrust.h"
#include "audioevent.h"

Bow::Bow(int damage)
    :Weapon{"bow_drawn", damage} {}

void Bow::use(Engine& engine, Entity& attacker, Entity& defender) {
    std::shared_ptr<Event> hit{};
    hit->add_next(Hit(defender, damage));

    // Vec direction = defender.get_position() - attacker.get_position();
    // std::shared_ptr<Event> swing = engine.events.create_event<Swing>(sprite, direction);
    // std::shared_ptr<Event> lightning = std::make_shared<Lightning>(defender.get_position());
    // swing->add_next(lightning);
}