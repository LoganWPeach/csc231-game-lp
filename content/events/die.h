#pragma once
#include "engine.h"
#include "entity.h"
#include "event.h"

class Die : public Event {
public:
    Die(Entity& entity);
    void execute(Engine& engine) override;
private:
    Entity& entity;
};
