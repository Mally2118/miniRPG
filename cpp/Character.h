#pragma once

#include <string>

enum class HeroClass {
    Rogue,
    Warrior,
    Barbarian
};

struct Attributes
{
    int strength;
    int agility;
    int endurance;
};

struct Character {
    HeroClass heroClass;
    Attributes stats;

    int level;
    int health;
    int maxHealth;

    std::string weaponName;
    int weaponDamage;
};

// объявление функций
int getBaseHealth(HeroClass heroClass);
std::string getClassName(HeroClass heroClass);
Character createCharacter(HeroClass HeroClass);
void printCharacter(const Character& character);