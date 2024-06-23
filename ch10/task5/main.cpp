/*
    Вопрос 5:
        Что не так с каждым из этих фрагментов кода, и как это исправить?
*/

// a)
/*
int main()
{
    int array[]{ 0, 1, 2, 3 };

    // здесь нужно заменить знак <= на <
    for (std::size_t count{ 0 }; count <= std::size(array); ++count)
    {
        std::cout << array[count] << ' ';
    }

    std::cout << '\n';

    return 0;
}
*/

// b)
/*
int main()
{
    int x{ 5 };
    int y{ 7 };

    // следует убрать const...
    const int* ptr{ &x };
    std::cout << *ptr << '\n';
    // ...так как константный указатель доступен только для чтения
    *ptr = 6;
    std::cout << *ptr << '\n';
    ptr = &y;
    std::cout << *ptr << '\n';

    return 0;
}
*/

// c)
/*
void printArray(int array[])
{
    // цикл for можно записывать таким образом только при наличии метода begin
    for (int element : array)
    {
        std::cout << element << ' ';
    }
}

int main()
{
    int array[]{ 9, 7, 5, 3, 1 };

    printArray(array);

    std::cout << '\n';

    return 0;
}
*/

// d)
/*
int* allocateArray(const int length)
{
    int temp[length]{};
    return temp; // функция возвращает адрес локальной переменной, так что память следует выделить динамически
}
*/

// e)
/*
int main()
{
    double d{ 5.5 };
    int* ptr{ &d }; // типы не соответствуют
    std::cout << ptr << '\n';

    return 0;
}
*/

int main()
{
    
}
