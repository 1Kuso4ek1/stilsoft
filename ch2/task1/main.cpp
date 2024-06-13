/*
    Напишите программу в одном исходном файле (с именем main.cpp), 
    которая считывает два отдельных целых числа, вводимых пользователем,
    складывает их вместе и затем выводит ответ.
*/

#include <iostream>

int readNumber()
{
    int ret = 0;
    
    std::cout << "Enter a number: ";
    std::cin >> ret;

    return ret;
}

void writeAnswer(int answer)
{
    std::cout << "The answer is: " << answer << std::endl;
}

int main()
{
    int a = readNumber();
    int b = readNumber();

    writeAnswer(a + b);
}
