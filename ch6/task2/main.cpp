/*
    Вопрос 2:
        Напишите файл с именем constants.h, который поможет запуститься следующей программе.
        Если ваш компилятор поддерживает C++17, используйте переменные inline constexpr.
        В противном случае используйте обычные переменные constexpr.
        Для max_class_size вы можете выбрать любое значение.
*/

#include "constants.hpp"
 
#include <iostream>
 
int main()
{
	std::cout << "How many students are in your class? ";
	int students{};
	std::cin >> students;

	if (students > constants::max_class_size)
		std::cout << "There are too many students in this class" << std::endl;
	else
		std::cout << "This class isn't too large" << std::endl;

	return 0;
}
