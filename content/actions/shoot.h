#include "action.h"
#include "entity.h"
#include "vec.h"

class Shoot : public Action {
public:
    Shoot(Vec direction);
    Result perform(Engine& engine, std::shared_ptr<Entity> entity) override;

private:
    Vec direction;
};