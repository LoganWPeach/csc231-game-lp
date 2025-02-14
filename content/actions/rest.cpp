#include "rest.h"
#include "entity.h"

Result Rest::perform(Engine& engine, std::shared_ptr<Entity> entity) {
    entity->take_damage(0);
    return success();
}
