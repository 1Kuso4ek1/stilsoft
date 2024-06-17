/*
    Вопрос 5:
        Найдите 3 проблемы (затрагивающие 4 строки) в следующем коде.
*/

#include <cstdint>
#include <iostream>

constexpr std::uint_least16_t drivingAge = 16;
 
int main()
{
    std::cout << "How old are you?\n";

    //std::uint8_t age{}; // std::uint8_t поведет себя как символ, можно заменить на std::uint_least16_t
    std::uint_least16_t age{};
    std::cin >> age;

    std::cout << "Allowed to drive a car in Texas [";

    //if (age >= 16) // Следует избегать магических чисел - определить константу constexpr std::uint_least16_t drivingAge = 16;
    if (age >= drivingAge)
        //std::cout << "x"; // Одиночные символы лучше заключать в '
        std::cout << 'x';
    else
        //std::cout << " "; // То же самое
        std::cout << ' ';

    std::cout << "]\n";

    return 0;
}
