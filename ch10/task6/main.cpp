/*
    Вопрос 6:
        Представим, что мы пишем карточную игру.

        a) В колоде 52 уникальных карты (13 рангов карт по 4 масти). Создайте перечисления для рангов карт (2, 3, 4, 5, 6, 7, 8, 9, 10, валет (Jack), дама (Queen), король (King), туз (Ace)) и мастей (трефы (clubs), бубны (diamonds), червы (hearts), пики (spades)). Эти перечислители не будут использоваться для индексации массивов.

        b) Каждая карта будет представлена структурой с именем Card, которая содержит ранг (rank) и масть (suit). Создайте структуру.

        c) Создайте функцию printCard(), которая принимает ссылку на const Card в качестве параметра и печатает ранг и масть карты в виде двухбуквенного кода (например, пиковый валет будет печататься как JS (от jack spades)).

        d) В колоде 52 карты. Создайте массив (используя std::array) для представления колоды карт и инициализируйте его по одной карте каждого типа. Сделайте это в функции с именем createDeck и вызовите createDeck из main. createDeck должен вернуть колоду в main.

        Подсказка: используйте static_cast, если вам нужно преобразовать целочисленный тип int в перечислимый тип.

        e) Напишите функцию с именем printDeck(), которая принимает колоду в качестве параметра константной ссылки и печатает карты в колоде. Используйте цикл for на основе диапазона. Когда вы вызовете printDeck с колодой, которую вы создали в предыдущей задаче, вывод должен быть таким:

        2C 3C 4C 5C 6C 7C 8C 9C TC JC QC KC AC 2D 3D 4D 5D 6D 7D 8D 9D TD JD QD KD AD 2H 3H 4H 5H 6H 7H 8H 9H TH JH QH KH AH 2S 3S 4S 5S 6S 7S 8S 9S TS JS QS KS AS

        Если вы использовали другие символы, это нормально.

        f) Напишите функцию с именем shuffleDeck для перетасовки колоды карт с помощью std::shuffle. Обновите свою функцию main, чтобы перетасовать колоду и распечатать ее уже перетасованной.

        Напоминание: инициализируйте генератор случайных чисел только один раз.

        g) Напишите функцию с именем getCardValue(), которая возвращает значение карты (например, 2 стоит 2, десятка, валет, дама или король стоят 10. Предположим, что туз стоит 11).
*/

#include <iostream>
#include <vector>
#include <random>
#include <array>
#include <algorithm>

enum class Rank
{
    Rank2, Rank3, Rank4, Rank5, Rank6,
    Rank7, Rank8, Rank9, Rank10,
    Jack, Queen, King, Ace, RanksCount
};

enum class Suit
{
    Clubs, Diamonds, Hearts, Spades, SuitsCount
};

struct Card
{
    Rank rank;
    Suit suit;
};

using deck_t = std::array<Card, 52>;

std::random_device dev;
std::default_random_engine eng(dev());

char rankToChar(Rank rank)
{
    switch(rank)
    {
    case Rank::Rank2: return '2';
    case Rank::Rank3: return '3';
    case Rank::Rank4: return '4';
    case Rank::Rank5: return '5';
    case Rank::Rank6: return '6';
    case Rank::Rank7: return '7';
    case Rank::Rank8: return '8';
    case Rank::Rank9: return '9';
    case Rank::Rank10: return 'T';
    case Rank::Jack: return 'J';
    case Rank::Queen: return 'Q';
    case Rank::King: return 'K';
    case Rank::Ace: return 'A';
    }

    return ' ';
}

char suitToChar(Suit suit)
{
    switch(suit)
    {
    case Suit::Clubs: return 'C';
    case Suit::Diamonds: return 'D';
    case Suit::Hearts: return 'H';
    case Suit::Spades: return 'S';
    }

    return ' ';
}

void printCard(const Card& card)
{
    std::cout << rankToChar(card.rank) << suitToChar(card.suit);
}

int getCardValue(const Card& card)
{
    switch(card.rank)
    {
    case Rank::Rank2: return 2;
    case Rank::Rank3: return 3;
    case Rank::Rank4: return 4;
    case Rank::Rank5: return 5;
    case Rank::Rank6: return 6;
    case Rank::Rank7: return 7;
    case Rank::Rank8: return 8;
    case Rank::Rank9: return 9;
    case Rank::Rank10:
    case Rank::Jack:
    case Rank::Queen:
    case Rank::King: return 10;
    case Rank::Ace: return 11;
    }

    return 0;
}

deck_t createDeck()
{
    deck_t ret;

    int count = 0;
    for(int i = 0; i < static_cast<int>(Suit::SuitsCount); i++)
        for(int j = 0; j < static_cast<int>(Rank::RanksCount); j++)
            ret[count++] = { static_cast<Rank>(j), static_cast<Suit>(i) };

    return ret;
}

void printDeck(const deck_t& deck)
{
    for(auto& i : deck)
    {
        printCard(i);
        std::cout << " ";
    }

    std::cout << std::endl;
}

void shuffleDeck(deck_t& deck)
{
    std::shuffle(deck.begin(), deck.end(), eng);
}

int main()
{
    deck_t deck { createDeck() };

    std::cout << "Deck before shuffling: " << std::endl;
    printDeck(deck);

    shuffleDeck(deck);

    std::cout << "Deck after shuffling: " << std::endl;
    printDeck(deck);
}
