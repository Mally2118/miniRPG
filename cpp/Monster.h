#pragma once

#include <string>
#include "Character.h"
#include "Weapon.h"

enum class MonsterType {
    Goblin,
    Skeleton,
    Slime,
    Ghost,
    Golem,
    Dragon
};

struct Monster
{
    MonsterType type;
    std::string name;

    Attributes stats;

    int health;
    int maxHealth;
    int weaponDamage;

    Weapon loot;
};

Monster createMonster(MonsterType type);
Monster createRandomMonster();
void printMonster(const Monster& monster);
