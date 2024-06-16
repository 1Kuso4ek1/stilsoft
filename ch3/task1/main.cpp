/*
    Используйте встроенный отладчик, чтобы пошагово выполнить следующую программу и отследить значение x.
    На основании полученной информации исправьте программу:
*/

#include <iostream>

/*

    Исходный вариант

int readNumber(int x)
{
	std::cout << "Please enter a number: ";
	std::cin >> x;
	return x;
}
 
void writeAnswer(int x)
{
	std::cout << "The sum is:" << x;
}
 
int main()
{
	int x {};
	readNumber(x);
	x = x + readNumber(x);
	writeAnswer(x);
 
	return 0;
}
*/

// Исправленный вариант

int readNumber()
{
    int x;
	std::cout << "Please enter a number: ";
	std::cin >> x;
	return x;
}
 
void writeAnswer(int x)
{
	std::cout << "The sum is: " << x << std::endl;
}
 
int main()
{
	int x = readNumber();
	x += readNumber();
    
	writeAnswer(x);
 
	return 0;
}
