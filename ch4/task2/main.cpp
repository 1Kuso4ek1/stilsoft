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
