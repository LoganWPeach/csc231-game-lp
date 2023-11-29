#include "event.h"
#include "sprite.h"

class Entity;

class Thrust : public Event {
public:
    Thrust(Sprite& sprite, Vec direction);
    // weapon sprite^ entity facing^

    void execute(Engine& engine);
    void when_done(Engine& engine);
private:
    Sprite& sprite;
    Sprite copy;
    Vec direction;

};