/*
    Вопрос 3:
        Напишите свою собственную функцию для обмена значениями двух целочисленных переменных.
        Напишите функцию main(), чтобы проверить ее.
*/

#include <iostream>

void swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    int a = 3, b = 5;

    std::cout << "Before swap: " << a << " " << b << std::endl;

    swap(a, b);

    std::cout << "After swap: " << a << " " << b << std::endl;
}
