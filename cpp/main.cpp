#include <iostream>

// возможные классный персонажа
enum class HeroClass {
    Rogue,
    Warrior,
    Barbarian
};

// характеристики персонажа
struct Attributes {
    int strength;
    int agility;
    int endurance;
};

// базовое здоровье класса
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

int main() {
    // характериски из примера ТЗ
    Attributes stats{1, 3, 2};

    // в качестве примера выберем разбойника
    HeroClass heroClass = HeroClass::Rogue;

    int maxHealth = getBaseHealth(heroClass) + stats.endurance;

    std::cout << "Hero HP: " << maxHealth << '\n';

    return 0;
}