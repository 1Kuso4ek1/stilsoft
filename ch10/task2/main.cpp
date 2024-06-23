/*
    Вопрос 2:
        Напишите следующую программу: создайте структуру, содержащую имя студента и его оценку (по шкале от 0 до 100).
        Спросите пользователя, сколько студентов он хочет ввести.
        Создайте std::vector для хранения данных всех студентов.
        Затем запросите у пользователя каждое имя и оценку.
        После того, как пользователь ввел все пары имен и оценок, отсортируйте список по оценкам (сначала самая высокая).
        Затем выведите все имена и оценки в отсортированном порядке.
        Для следующего ввода:

            Joe
            82
            Terry
            73
            Ralph
            4
            Alex
            94
            Mark
            88

        Вывод должен выглядеть так:

            Alex got a grade of 94
            Mark got a grade of 88
            Joe got a grade of 82
            Terry got a grade of 73
            Ralph got a grade of 4

        Вы можете предположить, что имена не содержат пробелов и что извлечение входных данных не завершается ошибкой.
*/

#include <iostream>
#include <vector>
#include <algorithm>

struct Student
{
    std::string name;
    int grade;
};

bool operator>(const Student& left, const Student& right)
{
    return left.grade > right.grade;
}

void printStudents(const std::vector<Student>& students)
{
    for(auto& i : students)
        std::cout << i.name << " got a grade of " << i.grade << std::endl;
}

int main()
{
    std::vector<Student> students;
    int studentsCount;

    std::cout << "Input the number of students: ";
    std::cin >> studentsCount;

    for(int i = 0; i < studentsCount; i++)
    {
        Student student;

        std::cout << "Enter name: "; std::cin >> student.name;
        std::cout << "Enter grade: "; std::cin >> student.grade;

        students.push_back(student);
    }

    std::sort(students.begin(), students.end(), std::greater<Student>());
    
    printStudents(students);
}
