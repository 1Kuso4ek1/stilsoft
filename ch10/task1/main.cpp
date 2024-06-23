/*
    Вопрос 1:
        Представьте, что вы пишете игру, в которой игрок может держать в руках 3 типа предметов:
        зелья здоровья (health potion), факелы (torch) и стрелы (arrow).
        Создайте перечисление для идентификации различных типов элементов и массив std::array для хранения количества единиц каждого элемента,
        который несет игрок (перечислители используются в качестве индексов массива).

        Игрок должен начать с 2 зельями здоровья, 5 факелами и 10 стрелами.
        Напишите функцию countTotalItems(), которая возвращает общее количество элементов, которые есть у игрока.
        Заставьте вашу функцию main() распечатать выходное значение countTotalItems(), а также количество факелов.
*/

#include <iostream>
#include <array>
#include <algorithm>
#include <numeric>

enum ItemType
{
    HealthPotion,
    Torch,
    Arrow
};

int countTotalItems(const std::array<int, 3>& inventory)
{
    return std::reduce(inventory.begin(), inventory.end());
}

int main()
{
    std::array<int, 3> inventory { 2, 5, 10 };

    std::cout << "Total items in inventory: " << countTotalItems(inventory) << std::endl;
    std::cout << "The number of torches: " << inventory[Torch] << std::endl;
}
