#include <iostream>
#include "Character.h"
#include "Monster.h"

int main() {
    int choice = 0;
    std::string answer;

    do {
        std::cout << "\nChoose your class:\n";
        std::cout << "1. Rogue\n";
        std::cout << "2. Warrior\n";
        std::cout << "3. Barbarian\n";

        while(true) {
        std::cout << "\nYour choice: ";
        
        if (std::cin >> choice && choice >= 1 && choice <= 3) {
            break;
        }
        std::cout << "Invalide choice. Try again.\n";
        std::cin.clear();
        if (std::cin.eof())
            return 0;
        std::cin.ignore(10000, '\n');
    }

        HeroClass selectedClass = static_cast<HeroClass>(choice - 1);
        Character hero = createCharacter(selectedClass);
        printCharacter(hero);

        Monster enemy = createRandomMonster();
        printMonster(enemy);

        std::cout << "\nCreate a new character? (y/n): ";
        std::cin >> answer;
    } while (answer == "y" && std::cin);

    return 0;
}