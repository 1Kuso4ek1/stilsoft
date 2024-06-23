/*
    Вопрос 7:
        а) Хорошо, время бросить вызов! Напишем упрощенную версию блэкджека.
            Вот правила нашей версии блэкджека:

            для начала дилер получает одну карту (в реальной жизни дилер получает две, но одна закрыта, поэтому на данном этапе это не имеет значения);
            для начала игрок получает две карты;
            игрок ходит первым.
            игрок может многократно сказать «еще» (hit) или сказать «достаточно» (stand);
            если игрок говорит «достаточно», его ход заканчивается, и его счет рассчитывается на основе карт, которые ему были розданы;
            если игрок говорит «еще», он получает еще одну карту, и значение этой карты добавляется к его общему счету;
            туз обычно засчитывается как 1 или 11 (в зависимости от того, что лучше для общего счета); для простоты мы будем считать здесь 11;
            если у игрока больше 21 очка, он сразу же проигрывает;
            дилер ходит после игрока;
            дилер несколько раз тянет карты, пока не наберет 17 или более очков, после чего он останавливается;
            если у дилера больше 21 очков, он проигрывает, и игрок немедленно выигрывает;
            в противном случае, если у игрока больше очков, чем у дилера, игрок выигрывает. В противном случае игрок проигрывает (для простоты мы будем рассматривать ничью как выигрыш дилера);
            в нашей упрощенной версии блэкджека мы не будем отслеживать, какие именно карты были сданы игроку и дилеру. Мы будем отслеживать только сумму значений карт, которые были розданы игроку и дилеру. Это упрощает работу.

            Начните с кода, который вы написали в вопросе 6. Создайте функцию с именем playBlackjack(). Эта функция должна:

                принимать в качестве параметра перетасованную колоду карт;
                реализовывать партию блэкджека, как описано выше;
                возвращать true, если выиграл игрок, и false, если он проиграл.

            Также напишите функцию main() для одиночной игры в блэкджек.
        b) Дополнительное задание: время критического мышления: опишите, как вы можете изменить приведенную выше программу, чтобы справиться со случаем, когда тузы могут быть равны 1 или 11.
        c) В реальном блэкджеке, если у игрока и дилера одинаковый счет (и у игрока нет перебора), результатом считается ничья, и ни один из них не выигрывает. Опишите, как бы вы изменили приведенную выше программу, чтобы учесть это.
*/

#include <iostream>
#include <vector>
#include <random>
#include <array>
#include <algorithm>
#include <numeric>

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

enum class BlackjackResult
{
    PlayerWon,
    DealerWon,
    Tie
};

struct Card
{
    Rank rank;
    Suit suit;
};

using deck_t = std::array<Card, 52>;
using hand_t = std::vector<Card>;

struct Player
{
    hand_t hand;
};

constexpr int maxScore = 21;
constexpr int dealerMinScore = 17;

deck_t::iterator deckIt;

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

int getCardValue(const Card& card, bool aceAs1 = false)
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
    case Rank::Ace: return aceAs1 ? 1 : 11;
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

void printHand(const hand_t& hand)
{
    for(auto& i : hand)
    {
        printCard(i);
        std::cout << " ";
    }
}

int calcHandValue(const hand_t& hand, bool aceAs1 = false)
{
    int acc = 0;
    for(auto& i : hand)
        acc += getCardValue(i, aceAs1);

    if(acc > maxScore && !aceAs1) // Туз за 1
        acc = calcHandValue(hand, true);

    return acc;
}

bool playerTurn(Player& player)
{
    int action = 0;
    enum Actions { Stand, Hit };

    do
    {
        std::cout << "Player: "; printHand(player.hand); std::cout << " (" << calcHandValue(player.hand) << " points)" << std::endl;

        if(calcHandValue(player.hand) > maxScore)
            return false;

        std::cout << "Type 1 to hit, or 0 to stand: ";
        std::cin >> action;

        if(action == Hit)
            player.hand.push_back(*deckIt++);

    } while(action != Stand);

    return true;
}

bool dealerTurn(Player& dealer)
{
    while(calcHandValue(dealer.hand) < dealerMinScore)
    {
        dealer.hand.push_back(*deckIt++);
        std::cout << "Dealer: "; printHand(dealer.hand); std::cout << " (" << calcHandValue(dealer.hand) << " points)" << std::endl;
    }

    return calcHandValue(dealer.hand) <= maxScore;
}

BlackjackResult playBlackjack(deck_t& deck)
{
    Player dealer { { *deckIt++ } };
    Player player { { *deckIt++, *deckIt++ } };

    std::cout << "Dealer: "; printHand(dealer.hand); std::cout << " (" << calcHandValue(dealer.hand) << " points)" << std::endl;

    if(!playerTurn(player))
        return BlackjackResult::DealerWon;

    if(!dealerTurn(dealer))
        return BlackjackResult::PlayerWon;

    int playerScore = calcHandValue(player.hand);
    int dealerScore = calcHandValue(dealer.hand);

    if(playerScore == dealerScore)
        return BlackjackResult::Tie; // Ничья

    return (playerScore > dealerScore ? BlackjackResult::PlayerWon : BlackjackResult::DealerWon);
}

int main()
{
    deck_t deck { createDeck() };

    shuffleDeck(deck);

    deckIt = deck.begin();

    switch(playBlackjack(deck))
    {
    case BlackjackResult::PlayerWon: std::cout << "You won!" << std::endl; break;
    case BlackjackResult::DealerWon: std::cout << "Dealer won!" << std::endl; break;
    case BlackjackResult::Tie: std::cout << "It's a tie!" << std::endl; break;
    }
}
