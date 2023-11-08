#pragma once

#include <memory>

class Entity;
class Engine;
class Action;

namespace Heros {

    void make_knight(std::shared_ptr<Entity> entity);

    std::unique_ptr<Action> behavior(Engine& engine, Entity&);
}
