#include <iostream>
#include "Character.h"

int main() {
    std::cout << "=== MINI RPG ===\n";
    std::cout << "\nChoose your class:\n";
    std::cout << "1. Rogue\n";
    std::cout << "2. Warrior\n";
    std::cout << "3. Barbarian\n";

    int choice = 0;

    while(true) {
        std::cout << "\nYour choice: ";
        
        if (std::cin >> choice && choice >= 1 && choice <= 3) {
            break;
        }
        std::cout << "Invalide choice. Try again.\n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    HeroClass selectedClass = static_cast<HeroClass>(choice - 1);

    Character hero = createCharacter(selectedClass);
    printCharacter(hero);

    return 0;
}