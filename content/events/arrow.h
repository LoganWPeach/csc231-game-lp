#pragma once

#include "entity.h"
#include "event.h"
#include "sprite.h"
#include "tile.h"
#include "vec.h"

class Arrow : public Event {
    Arrow(Entity& source, Sprite& sprite, Vec direction);
    void execute(Engine& engine) override;
    void when_done(Engine& engine) override;

private:
    Entity source;
    Sprite sprite;
    Tile origin;
    Vec direction;
};