#include "Weapon.h"

Weapon createWeapon(WeaponType type) {
    switch (type) {
        case WeaponType::Dagger:
            return {"Dagger", 2, DamageType::Piercing};
        case WeaponType::Sword:
            return {"Sword", 3, DamageType::Slashing};
        case WeaponType::Club:
            return {"Club", 3, DamageType::Blunt};
        case WeaponType::Axe:
            return {"Axe", 4, DamageType::Slashing};
        case WeaponType::Spear:
            return {"Spear", 3, DamageType::Piercing};
        case WeaponType::LegendarySword:
            return {"Legendary Sword", 10, DamageType::Slashing};
    }
    return {"Unknown", 0, DamageType::Blunt};
}

std::string getDamageTypeName(DamageType type) {
    switch (type)
    {
    case DamageType::Slashing: 
        return "Slashing";
    case DamageType::Blunt:
        return "Blunt";
    case DamageType::Piercing:
        return "Piercing";
    }
    return "Unknown";
}