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
