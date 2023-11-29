#pragma once

#include "weapon.h"

class Bigsword : public Weapon {
public:
    Bigsword(int damage);
    void use(Engine& engine, Entity& attacker, Entity& defender) override;
};