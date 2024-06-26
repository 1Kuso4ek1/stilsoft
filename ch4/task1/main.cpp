/*
    Вопрос 1:
        Почему символьные константы обычно лучше, чем литеральные константы?
        Почему символьные константы с const/constexpr обычно лучше, чем символьные константы с #define?
    Ответ:
        Использование символьных констант исключит использование "магических чисел"
        const/constexpr лучше, чем #define, потому что:
            1. Они видны в отладчике
            2. Не конфликтуют с кодом
            3. Подчиняются правилам области видимости

    Вопрос 2:
        a) возраст пользователя (в годах) - uint8_t

        b) нравится ли пользователю цвет, или нет - bool

        c) число пи (3,14159265) - constexpr double

        d) количество страниц в учебнике (предположим, что размер важен) - std::uint_least16_t

        e) длина дивана в метрах с точностью до 2 знаков после запятой - float

        f) сколько раз вы моргнули с момента своего рождения (примечание: ответ исчисляется миллионами) - std::uint_least32_t

        g) пользователь выбирает пункт в меню, в котором список пунктов пронумерован буквами - char

        h) год рождения (при условии, что размер важен) - std::int_least16_t

    Вопрос 3:
        Напишите следующую программу:
        Пользователя просят ввести 2 числа с плавающей запятой (используйте тип double).
        Затем пользователя просят ввести один из следующих математических символов: +, -, * или /.
        Программа вычисляет ответ, исходя из этих двух чисел, введенных пользователем, и печатает результаты в консоль.
        Если пользователь вводит неверный символ, программа не должна ничего печатать.
*/

#include <iostream>

double readDouble()
{
    double ret;
    std::cout << "Enter a double value: ";
    std::cin >> ret;

    return ret;
}

char readOperation()
{
    char ret;
    std::cout << "Enter one of the following: +, -, *, or /: ";
    std::cin >> ret;

    return ret;
}

void writeResult(double a, double b)
{
    switch(readOperation())
    {
    case '+':
        std::cout << a << " + " << b << " is " << a + b << std::endl;
        break;
    case '-':
        std::cout << a << " - " << b << " is " << a - b << std::endl;
        break;
    case '*':
        std::cout << a << " * " << b << " is " << a * b << std::endl;
        break;
    case '/':
        std::cout << a << " / " << b << " is " << a / b << std::endl;
        break;
    default:
        break;
    }
}

int main()
{
    double a = readDouble();
    double b = readDouble();

    writeResult(a, b);
}
