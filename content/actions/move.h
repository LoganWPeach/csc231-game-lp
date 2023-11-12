#include "action.h"
#include "vec.h"
#include "dungeon.h"

class Move : public Action {
public:
    Move(Vec direction);
    Result perform(Engine& engine, std::shared_ptr<Entity> entity) override;

private:
    Vec direction;
};
