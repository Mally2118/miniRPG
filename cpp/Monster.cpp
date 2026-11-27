#include "Monster.h"

#include <iostream>
#include <random>
#include <vector>

Monster createMonster(MonsterType type) {
    switch (type) {
        case MonsterType::Goblin:
            return {
                MonsterType::Goblin,
                "Goblin",
                {1, 1, 1},
                5,
                5,
                2,
                createWeapon(WeaponType::Dagger)
            };
        case MonsterType::Skeleton:
            return {
                MonsterType::Skeleton,
                "Skeleton",
                {2, 2, 1},
                10,
                10,
                2,
                createWeapon(WeaponType::Club)
            };
        case MonsterType::Slime:
            return {
                MonsterType::Slime,
                "Slime",
                {3, 1, 2},
                8,
                8,
                1,
                createWeapon(WeaponType::Spear)
            };
        case MonsterType::Ghost:
            return {
                MonsterType::Ghost,
                "Ghost",
                {1, 3, 1},
                6,
                6,
                3,
                createWeapon(WeaponType::Sword)
            };
        case MonsterType::Golem:
            return {
                MonsterType::Golem,
                "Golem",
                {3, 1, 3},
                10,
                10,
                1,
                createWeapon(WeaponType::Axe)
            };
        case MonsterType::Dragon:
            return {
                MonsterType::Dragon,
                "Dragon",
                {3, 3, 3},
                20,
                20,
                4,
                createWeapon(WeaponType::LegendarySword)
            };
        default: return {};
    }
}

Monster createRandomMonster() {
    static const std::vector<MonsterType> monsterTypes = {
        MonsterType::Goblin,
        MonsterType::Skeleton,
        MonsterType::Slime,
        MonsterType::Ghost,
        MonsterType::Golem,
        MonsterType::Dragon
    };

    static std::mt19937 generator(
        std::random_device{}()
    );

    std::uniform_int_distribution<int> dist(
        0,
        static_cast<int>(monsterTypes.size()) - 1
    );

    int index = dist(generator);

    return createMonster(monsterTypes[index]);
}

int getBaseDamageEnemy(const Monster& monster) {
    return monster.weaponDamage + monster.stats.strength;
}

void printMonster(const Monster& monster) {
    std::cout << "\n=== ENEMY ==\n";
    std::cout << "Name: " << monster.name << '\n';
    std::cout << "Health: " << monster.health << " / " << monster.maxHealth << '\n';
    std::cout << "Strength: " << monster.stats.strength << '\n';
    std::cout << "Agility: " << monster.stats.agility << '\n';
    std::cout << "Endurance: " << monster.stats.endurance << '\n';
    std::cout << "Total stats: " << monster.stats.endurance + monster.stats.strength + monster.stats.agility << '\n';
    std::cout << "Damage: " << getBaseDamageEnemy(monster) << '\n';
    std::cout << "Loot: " << monster.loot.name << '\n';
}