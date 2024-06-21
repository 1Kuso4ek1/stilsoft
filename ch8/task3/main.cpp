/*
    Вопрос 4:
        Что выдает эта программа и почему?
    Ответ:
        Она выдает 1212, так как сначала создаетсяи дважды вызывается функция count<int>, а потом также дважды вызывается другая функция - count<double>
*/

#include <iostream>

template <typename T>
int count(T x)
{
    static int c { 0 };
    return ++c;
}

int main()
{
    std::cout << count(1);
    std::cout << count(1);
    std::cout << count(2.3);
    std::cout << count<double>(1);
   
    return 0;
}
