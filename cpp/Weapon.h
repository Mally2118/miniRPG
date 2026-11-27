#pragma once
#include <string>

enum class DamageType {
    Slashing,
    Blunt,
    Piercing
};

enum class WeaponType {
    Dagger,
    Sword,
    Club,
    Axe,
    Spear,
    LegendarySword
};

struct Weapon
{
    std::string name;
    int damage;
    DamageType damageType;
};

Weapon createWeapon(WeaponType type);
std::string getDamageTypeName(DamageType type);
