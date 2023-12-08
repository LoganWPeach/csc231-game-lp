#include "bow.h"
#include "hit.h"
#include "engine.h"
#include "events.h"
#include "swing.h"
#include "thrust.h"
#include "audioevent.h"
#include "lightning.h"

Bow::Bow(int damage)
    :Weapon{"bow", damage} {
    sprite.shift.x -= 25;
}

void Bow::use(Engine& engine, Entity& attacker, Entity& defender) {
    Vec direction = defender.get_position() - attacker.get_position();
    std::shared_ptr<Event> swing = engine.events.create_event<Swing>(sprite, direction);
    std::shared_ptr<Event> lightning = std::make_shared<Lightning>(defender.get_position());
    swing->add_next(lightning);
}