#include "attack.h"
#include "engine.h"
#include "tile.h"
#include "weapon.h"

Attack::Attack(Entity& defender) : defender{defender} {}

Result Attack::perform(Engine& engine, std::shared_ptr<Entity> entity) {
    std::shared_ptr<Weapon> weapon = entity->get_weapon();
    weapon->use(engine, *entity, defender);
    return success();
}
