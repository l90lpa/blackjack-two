//
//  deck.cpp
//  blackjack-two
//
//  Created by Liam on 29/07/2016.
//  Copyright © 2016 Liam. All rights reserved.
//

#include <iostream>
#include "deck.hpp"

Deck::Deck()
{
    int index = 0;
    for(int suit = 0; suit < Card::CardSuit::SUIT_MAX; suit++)
    {
        for(int rank = 0; rank < Card::CardRank::RANK_MAX; rank++)
        {
            m_deck[index] = Card(static_cast<Card::CardRank>(rank), static_cast<Card::CardSuit>(suit));
            index++;
        }
    }
}

void Deck::printDeck()
{
    for(int x = 0; x < Card::SUIT_MAX; x++)
    {
        for(int y = 0; y < Card::RANK_MAX; y++)
        {
            int index = (x * Card::RANK_MAX) + y;
            m_deck[index].printCard();
            std::cout << ' ';
        }
        std::cout << '\n';
    }

}


int Deck::getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this value once
    // evenly distribute the random number across our range
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}


void Deck::swapCard(Card &a, Card &b)
{
    Card temp = a;
    a = b;
    b = temp;
}


void Deck::shuffleDeck()
{
    for(int index = 0; index < 52; index++)
    {
        swapCard(m_deck[index], m_deck[getRandomNumber(0, 51)]);
    }
}

