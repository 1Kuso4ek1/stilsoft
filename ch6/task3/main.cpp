/*
    Вопрос 3:
        Завершите следующую программу, написав функцию passOrFail(), которая должна возвращать true для первых 3 вызовов и false для последующих.
*/

#include <iostream>

const int maxUsersPass = 3;

bool passOrFail()
{
    static int counter = 0;

    return counter++ < maxUsersPass;
}
 
int main()
{
	std::cout << "User #1: " << (passOrFail() ? "Pass" : "Fail") << '\n';
	std::cout << "User #2: " << (passOrFail() ? "Pass" : "Fail") << '\n';
	std::cout << "User #3: " << (passOrFail() ? "Pass" : "Fail") << '\n';
	std::cout << "User #4: " << (passOrFail() ? "Pass" : "Fail") << '\n';
	std::cout << "User #5: " << (passOrFail() ? "Pass" : "Fail") << '\n';
 
	return 0;
}
