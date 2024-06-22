/*
    Вопрос 1:
        При разработке игры мы решаем, что нам нужны монстры, ведь всем нравится сражаться с монстрами.
        Объявите структуру, представляющую вашего монстра.
        Монстр должен иметь один из следующих типов: огр, дракон, орк, гигантский паук или слизь.
        Используйте для этого класс перечисления.

        У каждого отдельного монстра также должно быть имя (используйте std::string), а также количество здоровья, которое показывает, сколько урона он может получить до своей смерти.
        Напишите функцию с именем printMonster(), которая выводит на печать все члены структуры.
        Создайте экземпляр огра и слизи, инициализируйте их с помощью списка инициализаторов и передайте их в printMonster().

        Ваша программа должна выдать следующий результат:
            This Ogre is named Torg and has 145 health.
            This Slime is named Blurp and has 23 health.
*/

#include <iostream>

enum class MonsterType
{
    Ogre,
    Dragon,
    Orc,
    GiantSpider,
    Slime
};

struct Monster
{
    Monster(MonsterType type, std::string name, int health) : type(type), name(name), health(health) {}

    void printMonster()
    {
        std::cout << "This ";

        switch(type)
        {
        case MonsterType::Ogre:
            std::cout << "Ogre"; break;
        case MonsterType::Dragon:
            std::cout << "Dragon"; break;
        case MonsterType::Orc:
            std::cout << "Orc"; break;
        case MonsterType::GiantSpider:
            std::cout << "Giant spider"; break;
        case MonsterType::Slime:
            std::cout << "Slime"; break;
        default:
            break;
        }

        std::cout << " is named " << name << " and has " << health << " health." << std::endl;
    }

    MonsterType type;
    std::string name;
    int health;
};

int main()
{
    Monster ogre(MonsterType::Ogre, "Torg", 145);
    Monster slime(MonsterType::Slime, "Blurp", 23);

    ogre.printMonster();
    slime.printMonster();
}
