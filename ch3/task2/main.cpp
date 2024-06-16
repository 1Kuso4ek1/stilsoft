/*
    Используйте встроенный отладчик для пошагового выполнения следующей программы.
    Для входных данных введите 8 и 4.
    На основе полученной информации исправьте программу:
*/

#include <iostream>
 
int readNumber()
{
	std::cout << "Please enter a number:";
	int x {};
	std::cin >> x;
	return x;
}
 
void writeAnswer(int x)
{
	std::cout << "The quotient is:" << x << std::endl;
}
 
int main()
{
	int x{ };
	int y{ };
	x = readNumber();
	// x = readNumber(); - ошибка!
    y = readNumber();
	writeAnswer(x/y);
 
	return 0;
}
