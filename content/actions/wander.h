#include "action.h"
#include "vec.h"
#include "dungeon.h"

class Wander : public Action {
public:
    Result perform(Engine& engine, std::shared_ptr<Entity> entity) override;
};
