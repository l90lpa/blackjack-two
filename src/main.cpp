//
//  main.cpp
//  blackjack-two
//
//  Created by Liam on 29/07/2016.
//  Copyright © 2016 Liam. All rights reserved.
//

#include <iostream>
#include "card.hpp"
#include "deck.hpp"
#include "player.hpp"


char playersChoice()
{
    char choice;
    std::cout << "Do you want to hit (h) or stand (s): ";
    std::cin >> choice;
    return choice;
}

bool playBlackjack(Deck& deck)
{
    Player competitor;
    
    competitor.addScore(Player::PLAYERID_COMPUTER, deck.dealCard().getCardValue());
    competitor.printScore(Player::PLAYERID_COMPUTER);
    
    competitor.addScore(Player::PLAYERID_HUMAN, deck.dealCard().getCardValue());
    
    competitor.addScore(Player::PLAYERID_HUMAN, deck.dealCard().getCardValue());
    competitor.printScore(Player::PLAYERID_HUMAN);
    
    if(competitor.getScore(Player::PLAYERID_HUMAN) != 21)
    {
        while(1)
        {
            int choice = playersChoice();
            if(choice == 'h')
            {
                competitor.addScore(Player::PLAYERID_HUMAN, deck.dealCard().getCardValue());
                competitor.printScore(Player::PLAYERID_HUMAN);
            }
            else if(choice == 's')
            {
                break;
            }
            if(competitor.getScore(Player::PLAYERID_HUMAN) == 21)
                break;
            else if(competitor.getScore(Player::PLAYERID_HUMAN) > 21)
                return false;
        }
    }
    
    while(competitor.getScore(Player::PLAYERID_COMPUTER) < competitor.getScore(Player::PLAYERID_HUMAN))
    {
        competitor.addScore(Player::PLAYERID_COMPUTER, deck.dealCard().getCardValue());
        competitor.printScore(Player::PLAYERID_COMPUTER);
    }
    
    if(competitor.getScore(Player::PLAYERID_COMPUTER) > 21)
        return true;
    
    return (competitor.getScore(Player::PLAYERID_HUMAN) > competitor.getScore(Player::PLAYERID_COMPUTER));
}

int main()
{
    srand(static_cast<int>(time(0)));
    rand();
    
    Deck deck;
    deck.shuffleDeck();
    
    char playAgain = 'y';
    while (playAgain == 'y')
    {
        if(playBlackjack(deck))
            std::cout << "Congratulations, you win!!\n";
        else
            std::cout << "Sorry, you lost.\n";
        std::cout << "Would you like to play again, yes (y) or no (n)? ";
        std::cin >> playAgain;
    }
    
    std::cout << '\n';
    
    return 0;
}
