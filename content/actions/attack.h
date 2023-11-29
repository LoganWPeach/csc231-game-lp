#include "action.h"
#include "entity.h"

class Attack : public Action {
public:
    Attack(Entity& defender);
    Result perform(Engine& engine, std::shared_ptr<Entity> entity) override;

private:
    Entity defender;
};
