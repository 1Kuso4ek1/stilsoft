/*
    3c) Почему следующий код не компилируется?
    Ответ:
        В обоих случаях требуется преобразование типов, поэтому компилятор не может выбрать предпочтительную перегрузку
*/

#include <iostream>

void print(/*long*/int x)
{
    std::cout << "long " << x << '\n';
}

void print(double x)
{
    std::cout << "double " << x << '\n';
}

int main()
{
    print(5);

    return 0;
}
