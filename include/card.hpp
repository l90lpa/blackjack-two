//
//  card.hpp
//  blackjack-two
//
//  Created by Liam on 29/07/2016.
//  Copyright © 2016 Liam. All rights reserved.
//

#ifndef card_hpp
#define card_hpp

class Card
{
public:
    enum CardRank
    {
        RANK_2 = 2,
        RANK_3,
        RANK_4,
        RANK_5,
        RANK_6,
        RANK_7,
        RANK_8,
        RANK_9,
        RANK_10,
        RANK_JACK,
        RANK_QUEEN,
        RANK_KING,
        RANK_ACE,
        RANK_MAX
    };
    enum CardSuit
    {
        SUIT_HEART,
        SUIT_SPADE,
        SUIT_DIAMOND,
        SUIT_CLUB,
        SUIT_MAX
    };
private:
    CardRank m_rank;
    CardSuit m_suit;
public:
    Card(CardRank rank = RANK_2, CardSuit suit = SUIT_CLUB);
    
    void printCard() const;
    
    int getCardValue() const;
};


#endif /* card_hpp */

