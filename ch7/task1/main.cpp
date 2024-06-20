/*
    Задание 1:
        В главе 4 мы написали программу, имитирующую падение мяча с башни. Поскольку у нас еще не было циклов, мяч мог падать только 5 секунд.
        Возьмите приведенную ниже программу и измените ее так, чтобы мяч падал столько секунд, сколько необходимо, пока не достигнет земли.
*/

#include <iostream>
#include "constants.hpp"

double calculateHeight(double initialHeight, int seconds)
{
    double distanceFallen { myConstants::gravity * seconds * seconds / 2 };
    double heightNow { initialHeight - distanceFallen };
 
    // Проверяем, не ушли ли мы под землю
    // Если это так, устанавливаем высоту на уровне земли
    if (heightNow < 0.0)
        return 0.0;
    else
        return heightNow;
}

void printBallPath(double initialHeight)
{
    int time = 0;
    double height = initialHeight;

    do
    {
        std::cout << "At " << time << " seconds, the ball is at height: " << height << "\n";
    } while((height = calculateHeight(initialHeight, ++time)) > 0.0);

    std::cout << "At " << time << " seconds, the ball is on the ground." << std::endl;
}

int main()
{
    std::cout << "Enter the initial height of the tower in meters: ";
    double initialHeight;
    std::cin >> initialHeight;

    printBallPath(initialHeight);

    return 0;
}
