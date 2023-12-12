#pragma once

#include "entity.h"
#include "event.h"
#include "sprite.h"
#include "tile.h"
#include "vec.h"

class Arrow : public Event {
public:
    Arrow(Vec position, Vec distance);
    void execute(Engine& engine) override;
    void when_done(Engine& engine) override;

private:
    Sprite sprite;
    Vec position;
    Vec direction;
    Vec distance;
};