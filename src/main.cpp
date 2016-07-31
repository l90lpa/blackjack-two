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

char getPlayersChoice()
{
    char choice;
    std::cout << "Do you want to hit (h) or stand (s): ";
    std::cin >> choice;
    return choice;
}

bool playBlackjack(Deck& deck)
{
    int dealerScore{0};
    int playerScore{0};
    
    dealerScore = deck.dealCard().getCardValue();
    std::cout << "Dealer has score, " << dealerScore << ".";
    
    playerScore = deck.dealCard().getCardValue() + deck.dealCard().getCardValue();
    std::cout << "\nYou have score, " << playerScore << ".\n";
    
    while(1)
    {
        int choice = getPlayersChoice();
        if(choice == 'h')
        {
            playerScore += deck.dealCard().getCardValue();
            std::cout << "You have score, " << playerScore << ".\n";
        }
        else if(choice == 's')
            break;
        if(playerScore > 21)
            return false;
    }
    
    while(dealerScore < playerScore)
    {
        dealerScore += deck.dealCard().getCardValue();
        std::cout << "Dealer has score, " << dealerScore << ".\n";
    }
    
    if(dealerScore > 21)
        return true;
    
    return (playerScore > dealerScore);
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
