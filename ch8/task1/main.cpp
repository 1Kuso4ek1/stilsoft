/*
    Вопрос 1:
        Какой тип преобразования происходит в каждом из следующих случаев?
        Допустимые ответы:
            преобразование не требуется, числовое продвижение, числовое преобразование,
            не будет компилироваться из-за сужающего преобразования.
        Предположим, что int и long равны 4 байтам.

    int main()
    {
        int a{ 5 };     // 1a
        int b{ 'a' };   // 1b
        int c{ 5.4 };   // 1c
        int d{ true };  // 1d
        int e{ static_cast<int>(5.4) }; // 1e
    
        double f { 5.0f }; // 1f
        double g { 5 };    // 1g
    
        // Немного посложнее
        long h{ 5 };     // 1h
    
        float i { f };   // 1i
        float j { 5.0 }; // 1j
    }

    1a) преобразование не требуется

    1b) числовое продвижение

    1c) не будет компилироваться из-за сужающего преобразования

    1d) числовое продвижение

    1e) числовое преобразование

    1f) числовое продвижение

    1g) числовое преобразование

    1h) числовое преобразование

    1i) не будет компилироваться из-за сужающего преобразования

    1j) числовое преобразование
*/

/*
    Вопрос 2:
        2a) Обновите следующую программу, используя псевдонимы типов:
            #include <iostream>
 
            namespace Constants
            {
                inline constexpr double pi { 3.14159 };
            }
            
            double convertToRadians(double degrees)
            {
                return degrees * Constants::pi / 180;
            }
            
            int main()
            {
                std::cout << "Enter a number of degrees: ";
                double degrees{};
                std::cin >> degrees;
            
                double radians { convertToRadians(degrees) };
                std::cout << degrees << " degrees is " << radians << " radians.\n";
            
                return 0;
            }
*/

#include <iostream>

typedef double radians_t;
typedef double degrees_t;

/*
    или
    
    using radians_t = double;
    using degrees_t = double;
*/

namespace Constants
{
    inline constexpr double pi { 3.14159 };
}

radians_t convertToRadians(degrees_t degrees)
{
    return degrees * Constants::pi / 180;
}

int main()
{
    std::cout << "Enter a number of degrees: ";
    degrees_t degrees{};
    std::cin >> degrees;

    radians_t radians { convertToRadians(degrees) };

    // 2b) Основываясь на вопросе 2a, объясните, почему следующая инструкция будет или не будет компилироваться:
    // radians = degrees;
    // Эта инструкция компилируется, поскольку изначальные типы у псевдонимов одинаковые

    std::cout << degrees << " degrees is " << radians << " radians.\n";

    return 0;
}
