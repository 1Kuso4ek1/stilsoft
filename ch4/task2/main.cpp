/*
Вопрос 4:
    Напишите короткую программу для имитации падения мяча с башни.
    Для начала у пользователя следует спросить высоту башни в метрах.
    Предположим, что ускорение свободного падения – обычное (9,8 м/с2), и что мяч не имеет начальной скорости (мяч не движется до старта).
    Программа должна вывести высоту мяча над землей через 0, 1, 2, 3, 4 и 5 секунд.
    Мяч не должен уходить под землю (высота 0).
*/

#include <iostream>
#include <cmath>

#include "constants.hpp"

double Sfall(double t)
{
    return (g * std::pow(t, 2)) / 2;
}

double readTowerHeight()
{
    double ret;
    std::cout << "Enter the height of the tower in meters: ";
    std::cin >> ret;

    return ret;
}

void writeResultAtTime(double t, double height)
{
    double ballHeight = height - Sfall(t);

    if(ballHeight > 0.0)
        std::cout << "At " << t << " seconds, the ball is at height: " << ballHeight << " meters" << std::endl;
    else std::cout << "At " << t << " seconds, the ball is on the ground." << std::endl;
}

int main()
{
    double height = readTowerHeight();

    writeResultAtTime(0, height);
    writeResultAtTime(1, height);
    writeResultAtTime(2, height);
    writeResultAtTime(3, height);
    writeResultAtTime(4, height);
    writeResultAtTime(5, height);
}
