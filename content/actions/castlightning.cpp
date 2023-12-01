#include "castlightning.h"
#include "engine.h"
#include "entity.h"
#include "lightning.h"
#include "randomness.h"

Result CastLightning::perform(Engine& engine, std::shared_ptr<Entity> entity) {
    auto [px,py] = entity->get_position();
    while (true) {
        int x = randint(px - 1, px + 1);
        int y = randint(py - 1, py + 1);
        Tile tile = engine.dungeon.get_tile(Vec{x,y});
        if (engine.dungeon.tiles.within_bounds({x,y}) && !tile.has_door()) {
            px = x;
            py = y;
            break;
        }
    }
    engine.events.create_event<Lightning>(Vec{px,py});
    return success();
}