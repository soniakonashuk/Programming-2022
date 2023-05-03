#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std;
class Card
{
public:
    enum Rank//ранг
    {
        TWO = 2,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN,
        EIGHT,
        NINE,
        TEN,
        JACK,
        QUEEN,
        KING,
        ACE
    };
    enum Suit//масть
    {
        CLUBS,
        DIAMONDS,
        HEARTS,
        SPADES
    };
    Card(Rank rank = ACE, Suit suit = SPADES) : m_Rank(rank), m_Suit(suit) {}// ace 11 spaces - піка
    int getValue() const{ //Це значення потім використовується для порівняння карт у грі та визначення переможця кожного раунду.
    
        if (m_Rank == JACK || m_Rank == QUEEN || m_Rank == KING)
        {
            return 10;
        }
        else if (m_Rank == ACE)
        {
            return 11;
        }
        else
        {
            return m_Rank;
        }
    }
    friend ostream& operator<<(ostream& os, const Card& card)
    {
        string ranks[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10",
                               "Jack", "Queen", "King", "Ace" };
        string suits[] = { "Clubs", "Diamonds", "Hearts", "Spades" };
        os << ranks[card.m_Rank - 2] << " of " << suits[card.m_Suit];
        return os;
    }

private:
    Rank m_Rank; //ранг та масть для кожної карти
    Suit m_Suit;
};

class Player
{
public:
    Player(const string& name) : m_Name(name) {}
    const string& getName() const
    {
        return m_Name;
    }
    void addCard(const Card& card)
    {
        m_Deck.push(card);
    }
    int getDeckSize() const //повертає кількість карт, які залишились в колоді гравця
    {
        return m_Deck.size();
    }
    bool hasCards() const
    {
        return !m_Deck.empty();
    }
    Card getTopCard()//повертає верхню карту з колоди гравця , видаляє її з колоди гравця
    {
        Card topCard = m_Deck.top();
        m_Deck.pop();
        return topCard;
    }

private:
    string m_Name;
    stack<Card> m_Deck;//колода гравця
};

class Game
{
public:
    Game(const string& player1Name, const string& player2Name)
        : m_Player1(player1Name), m_Player2(player2Name)
    {
        vector<Card> deck;
        for (int suit = Card::CLUBS; suit <= Card::SPADES; ++suit)// створює колоду з усіх можливих карт (52 штуки) за допомогою вкладених циклів змінюючи масть та ранг. 
        {
            for (int rank = Card::TWO; rank <= Card::ACE; ++rank)
            {
                deck.push_back(Card(static_cast<Card::Rank>(rank),
                    static_cast<Card::Suit>(suit)));
            }
        }
        shuffleDeck(deck);// перемішування колоди та розділяється між гравцями
        for (int i = 0; i < deck.size(); ++i)
        {
            if (i % 2 == 0)
            {
                m_Player1.addCard(deck[i]);//кожній 2 карті з колоди присвоюємо граця
            }
            else
            {
                m_Player2.addCard(deck[i]);
            }
        }
    }
    void play()
    {
        cout << "Starting the game of War!" << endl;
        int round = 1;
        while (m_Player1.hasCards() && m_Player2.hasCards())
        {
           cout << "Round " << round << ":" << endl;
            cout << m_Player1.getName() << " has " << m_Player1.getDeckSize()
                << " cards remaining." << endl;
            cout << m_Player2.getName() << " has " << m_Player2.getDeckSize()
                << " cards remaining." << endl;

            Card p1Card = m_Player1.getTopCard();
            Card p2Card = m_Player2.getTopCard();

            cout << m_Player1.getName() << " plays " << p1Card << endl;
            cout << m_Player2.getName() << " plays " << p2Card << endl;

            if (p1Card.getValue() > p2Card.getValue())//якщо карту першого гравця >, то він отримує дві карти
            {
                cout << m_Player1.getName() << " wins the round!" << endl;
                m_Player1.addCard(p1Card);
                m_Player1.addCard(p2Card);
            }
            else if (p2Card.getValue() > p1Card.getValue())//якщо карта другого гравця >, то він отримує обидві карти
            {
                cout << m_Player2.getName() << " wins the round!" << endl;
                m_Player2.addCard(p2Card);
                m_Player2.addCard(p1Card);
            }
            else
            {
                cout << "War!" << endl; //якщо карти рівні, то відбувається війна
                cout << "War!" << endl; 
                vector<Card> warCards;
                warCards.push_back(p1Card);
                warCards.push_back(p2Card);
                playWar(warCards);
            }
            cout << endl;
            round++;
        }
        if (m_Player1.hasCards())
        {
            cout << m_Player1.getName() << " wins the game!" << endl;
        }
        else
        {
            cout << m_Player2.getName() << " wins the game!" << endl;
        }
    }

private:
    void shuffleDeck(vector<Card>& deck) //перемішує ви падковим чином
    {
        mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); //мережа генераторів 
        shuffle(deck.begin(), deck.end(), rng);
    }
    void playWar(vector<Card>& warCards)
    {
        if (m_Player1.getDeckSize() < 4 || m_Player2.getDeckSize() < 4)
        {
            if (m_Player1.getDeckSize() < 4)
            {
                cout << m_Player1.getName() << " doesn't have enough cards for war!" << endl;
                m_Player2.addCard(warCards[0]);
                m_Player2.addCard(warCards[1]);
                m_Player2.addCard(warCards[2]);
                m_Player2.addCard(warCards[3]);
            }
            else
            {
                cout << m_Player2.getName() << " doesn't have enough cards for war!" << endl;
                m_Player1.addCard(warCards[0]);
                m_Player1.addCard(warCards[1]);
                m_Player1.addCard(warCards[2]);
                m_Player1.addCard(warCards[3]);
            }
        }
        else
        {
            cout << "Each player puts down 3 cards for war!" <<endl;
            for (int i = 0; i < 3; ++i)
            {
                warCards.push_back(m_Player1.getTopCard());
                warCards.push_back(m_Player2.getTopCard());
            }
            Card p1Card = m_Player1.getTopCard();
            Card p2Card = m_Player2.getTopCard();
            cout << m_Player1.getName() << " plays " << p1Card << endl;
            cout << m_Player2.getName() << " plays " << p2Card << endl;
            if (p1Card.getValue() > p2Card.getValue())
            {
                cout << m_Player1.getName() << " wins the war!" << endl;
                for (int i = 0; i < warCards.size(); ++i)
                {
                    m_Player1.addCard(warCards[i]);
                }
                m_Player1.addCard(p1Card);
                m_Player1.addCard(p2Card);
            }
            else if (p2Card.getValue() > p1Card.getValue())
            {
                cout << m_Player2.getName() << " wins the war!" << endl;
                for (int i = 0; i < warCards.size(); ++i)
                {
                    m_Player2.addCard(warCards[i]);
                }
                m_Player2.addCard(p2Card);
                m_Player2.addCard(p1Card);
            }
            else
            {
                cout << "Another war!" << endl;
                playWar(warCards);
            }
        }
    }
    Player m_Player1;
    Player m_Player2;
};//Після перемоги гравця він отримує всі картки, що брали участь у війні, а також дві зіграні картки, які виграв гравець.

int main() {
    string player1Name, player2Name;
    cout << "Enter player 1's name: ";
    getline(cin, player1Name);
    cout << "Enter player 2's name: ";
    getline(cin, player2Name);
    Game game(player1Name, player2Name);
    game.play();
    return 0;
}