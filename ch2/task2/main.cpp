/*
    Измените программу, которую вы написали в ответе на вопрос 1,
    чтобы readNumber() и writeAnswer() находились в отдельном файле с именем io.cpp.
    Для доступа к ним из main() используйте предварительное объявление.
*/

int readNumber();

void writeAnswer(int answer);

int main()
{
    int a = readNumber();
    int b = readNumber();

    writeAnswer(a + b);
}
