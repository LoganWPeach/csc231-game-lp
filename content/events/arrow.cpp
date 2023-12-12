#include "arrow.h"
#include "engine.h"

Arrow::Arrow(Vec position, Vec distance) : position{position}, direction{distance}, distance{distance} {
    direction = coordinate(direction);
}

void Arrow::execute(Engine& engine) {
    if (frame_count == 0) {
        sprite = engine.graphics.get_sprite("arrow");
        number_of_frames = abs(distance.x) + abs(distance.y);
        if (direction == Vec{0,1}) {
            sprite.angle = 0;
        }
        else if (direction == Vec{1,0}) {
            sprite.angle = 90;
        }
        else if (direction == Vec{0,-1}) {
            sprite.angle = 180;
        }
        else if (direction == Vec{-1,0}) {
            sprite.angle = -90;
        }
    }
    sprite.shift.x += (direction.x)*16;
    sprite.shift.y += (direction.y)*-16;
    engine.camera.add_overlay(position, sprite);
}
void Arrow::when_done(Engine& engine) {

}
