#include "action.h"
#include "vec.h"
#include "dungeon.h"

class Move2 : public Action {
public:
    Move2(Vec direction);
    Result perform(Engine& engine, std::shared_ptr<Entity> entity) override;

private:
    Vec direction;
};