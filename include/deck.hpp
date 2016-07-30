//
//  deck.hpp
//  blackjack-two
//
//  Created by Liam on 29/07/2016.
//  Copyright © 2016 Liam. All rights reserved.
//

#ifndef deck_hpp
#define deck_hpp

#include <array>
#include <iostream>
#include "card.hpp"

class Deck
{
private:
    std::array<Card, 52>m_deck;
    static int getRandomNumber(int, int);
    static void swapCard(Card&, Card&);
    int m_cardIndex;
public:
    Deck();
    void printDeck();
    void shuffleDeck();
    const Card& dealCard();
};

#endif /* deck_hpp */
