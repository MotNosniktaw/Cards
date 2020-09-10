// Cards.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <time.h>

using namespace std;

class Card {
public:
    Card(int value, string suit) {
        Value = value;
        Suit = suit;
    }

    int GetValue() {
        return Value;
    }

    string GetSuit() {
        return Suit;
    }

    bool GetFaceUp() {
        return FaceUp;
    }

    void FlipCard() {
        FaceUp = !FaceUp;
    }

private:
    int Value;
    string Suit;
    bool FaceUp = false;
};

class Deck {
private:
    vector<int> Values;
    vector<string> Suits;
    vector<Card> Cards;

public:
    Deck(vector<int> values, vector<string> suits) {
        Values = values;
        Suits = suits;

        vector<Card> cards;

        for(int value : Values)
        {
            for (string suit : Suits)
            {
                Card card = Card(value, suit);
                cards.push_back(card);
            }
        }

        Cards = cards;
    }

    void ShuffleDeck() {
        srand(unsigned(time(NULL)));
        std::random_shuffle(Cards.begin(), Cards.end());
    }

    void ReadCards() {
        for (Card card : Cards) {
            std::cout << card.GetValue() << " " << card.GetSuit() << endl;
        }
    }
};

int main()
{
    std::cout << "Hello World!\n";

    vector<int> values{ 1, 2, 3, 4, 5, 6, 7, 8 };
    vector<string> suits{ "Potato", "Carrot", "Turnip", "Suede" };

    Deck deck(values, suits);

    deck.ReadCards();
    std::cout << endl;
    deck.ShuffleDeck();
    deck.ReadCards();
    std::cout << endl;
    deck.ShuffleDeck();
    deck.ReadCards();
    std::cout << endl;
    deck.ShuffleDeck();
    deck.ReadCards();

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
