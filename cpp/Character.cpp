#include "Character.h"

#include <iostream>
#include <random>

// генератор случайных чисел
int randomStat() {
    static std::mt19937 generator(
        std::random_device{}()
    );

    std::uniform_int_distribution<int> dist(1, 3);

    return dist(generator);
}

int getBaseHealth(HeroClass heroClass) {
    switch (heroClass) {
        case HeroClass::Rogue:
            return 4;
        case HeroClass::Warrior:
            return 5;
        case HeroClass::Barbarian:
            return 6;
    }
    return 0;
}

int getBaseDamage(const Character& hero) {
    return hero.weaponDamage + hero.stats.strength;
}

std::string getClassName(HeroClass heroClass) {
    switch (heroClass)
    {
    case HeroClass::Rogue: 
        return "Rogue";
    case HeroClass::Warrior:
        return "Warrior";
    case HeroClass::Barbarian:
        return "Barbarian";
    }
    return "Unknown";
}

Character createCharacter(HeroClass heroClass) {
    Character hero{};

    hero.heroClass = heroClass;
    hero.level = 1;

    hero.stats.strength = randomStat();
    hero.stats.agility = randomStat();
    hero.stats.endurance = randomStat();

    hero.maxHealth = getBaseHealth(heroClass) + hero.stats.endurance;

    hero.health = hero.maxHealth;

    switch (heroClass)
    {
    case HeroClass::Rogue:
        hero.weaponName = "Dagger";
        hero.weaponDamage = 2;
        break;
    
    case HeroClass::Warrior:
        hero.weaponName = "Sword";
        hero.weaponDamage = 3;
        break;

    case HeroClass::Barbarian:
        hero.weaponName = "Club";
        hero.weaponDamage = 3;
        break;
    }

    return hero;
}

void printCharacter(const Character& hero) {
    std::cout << "\n=== YOUR CHARACTER ==\n";
    std::cout << "Class: " << getClassName(hero.heroClass) << '\n';
    std::cout << "Level: " << hero.level << '\n';
    std::cout << "Strength: " << hero.stats.strength << '\n';
    std::cout << "Agility: " << hero.stats.agility << '\n';
    std::cout << "Endurance: " << hero.stats.endurance << '\n';
    std::cout << "Total stats: " << hero.stats.endurance + hero.stats.strength + hero.stats.agility << '\n';
    std::cout << "Health: " << hero.health << " / " << hero.maxHealth << '\n';
    std::cout << "Weapon: " << hero.weaponName << '\n';
    std::cout << "Damage: " << getBaseDamage(hero) << '\n';
}