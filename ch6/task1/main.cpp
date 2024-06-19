/*
    Вопрос 1:
        Исправьте следующую программу:
*/

#include <iostream>
 
int main()
{
    std::cout << "Enter a positive number: ";
    int num{};
    std::cin >> num;

    /*
    неправильно
    if (num < 0)
        std::cout << "Negative number entered.  Making positive.\n";
        num = -num;
    */

    if (num < 0)
    {
        std::cout << "Negative number entered.  Making positive.\n";
        num = -num;
    }

    std::cout << "You entered: " << num << std::endl;

    return 0;
}
