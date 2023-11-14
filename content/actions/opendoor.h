#include "action.h"
#include "vec.h"

class Opendoor : public Action {
public:
    Opendoor(Vec direction);
    Result perform(Engine& engine, std::shared_ptr<Entity> entity) override;
private:
    Vec direction;
};
