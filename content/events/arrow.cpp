#include "arrow.h"
#include "engine.h"

Arrow::Arrow(Entity& source, Sprite& sprite, Vec direction) : source{source}, direction{direction} {}

void Arrow::execute(Engine& engine) {
    if (frame_count == 0) {
        sprite = engine.graphics.get_sprite("arrow");
        if (direction == Vec{1,0}) {
            sprite.angle = 90;
        }
        if (direction == Vec{-1,0}) {
            sprite.angle = -90;
        }
        if (direction == Vec{0,1}) {
            sprite.angle = 0;
        }
        if (direction == Vec{0,-1}) {
            sprite.angle = 0;
        }
        Tile target{};
        int checkiters{0};
        while (!target.has_door() && !target.has_entity() && !target.is_wall()) {
            ++checkiters;

        }
    }
    sprite.shift.x += 16.0;
}
void Arrow::when_done(Engine& engine) {

}
