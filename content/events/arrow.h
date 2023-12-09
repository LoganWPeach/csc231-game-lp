#pragma once

#include "entity.h"
#include "event.h"
#include "sprite.h"
#include "tile.h"
#include "vec.h"

class Arrow : public Event {
public:
    Arrow(Tile origin, Vec distance);
    void execute(Engine& engine) override;
    void when_done(Engine& engine) override;

private:
    Sprite sprite;
    Tile origin;
    Vec direction;
    Vec distance;
};