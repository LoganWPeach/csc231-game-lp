#pragma once
#include "engine.h"
#include "event.h"

class Hit : public Event {
public:
    Hit(Entity& entity, int damage);
    void execute(Engine& engine) override;
    void when_done(Engine& engine) override;
private:
    Entity& entity;
    int damage;
};