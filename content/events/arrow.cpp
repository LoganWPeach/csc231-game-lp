#include "arrow.h"
#include "engine.h"

Arrow::Arrow(Tile origin, Vec distance) : origin{origin}, direction{distance}, distance{distance} {
    direction = coordinate(direction);
}

void Arrow::execute(Engine& engine) {

    if (frame_count == 0) {
        number_of_frames = distance.x + distance.y;

    }
    sprite.shift.x += (direction.x)*16;
    sprite.shift.y += (direction.y)*16;
}
void Arrow::when_done(Engine& engine) {

}
