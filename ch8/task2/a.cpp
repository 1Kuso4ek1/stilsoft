/*
    Вопрос 3:
        3a) Что выдает эта программа и почему?
    
    Ответ:
        Программа выдает int 5, поскольку для выполнения этой функции не требуется преобразование типов
*/

#include <iostream>

void print(int x)
{
    std::cout << "int " << x << '\n';
}

void print(double x)
{
    std::cout << "double " << x << '\n';
}

int main()
{
    short s { 5 };
    print(s);

    return 0;
}
