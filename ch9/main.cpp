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

std::string monsterTypeToString(MonsterType type)
{
    switch(type)
    {
    case MonsterType::Ogre:
        return "Ogre";
    case MonsterType::Dragon:
        return "Dragon";
    case MonsterType::Orc:
        return "Orc";
    case MonsterType::GiantSpider:
        return "Giant spider";
    case MonsterType::Slime:
        return "Slime";
    }

    return "None";
}

struct Monster
{
    void printMonster()
    {
        std::cout << "This " << monsterTypeToString(type) << " is named " << name << " and has " << health << " health." << std::endl;
    }

    MonsterType type;
    std::string name;
    int health;
};

int main()
{
    Monster ogre { MonsterType::Ogre, "Torg", 145 };
    Monster slime { MonsterType::Slime, "Blurp", 23 };

    ogre.printMonster();
    slime.printMonster();
}
