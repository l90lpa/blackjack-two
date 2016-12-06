//
//  player.cpp
//  blackjack-two
//
//  Created by Liam on 05/12/2016.
//  Copyright © 2016 Liam. All rights reserved.
//

#include "player.hpp"

Player::Player()
{
    m_player[PLAYERID_COMPUTER].playerIndex = PLAYERID_COMPUTER;
    m_player[PLAYERID_COMPUTER].playerScore = 0;
    m_player[PLAYERID_HUMAN].playerIndex = PLAYERID_HUMAN;
    m_player[PLAYERID_HUMAN].playerScore = 0;
}



void Player::addScore(Player::playerID index, int cardValue, char testChoice)
{
    if(cardValue == 11)
    {
        switch(index)
        {
            case PLAYERID_COMPUTER:
            {
                if(m_player[index].playerScore <= 10)
                {
                    m_player[index].playerScore += 11;
                }
                else if(m_player[index].playerScore > 10)
                {
                    m_player[index].playerScore += 1;
                }
            }; break;
            case PLAYERID_HUMAN:
            {
                if(m_player[index].playerScore == 10)
                {
                    m_player[index].playerScore += 11;
                }
                else if(m_player[index].playerScore > 10)
                {
                    m_player[index].playerScore += 1;
                }
                else if(m_player[index].playerScore < 10)
                {
                    char choice = 'a';
                    do
                    {
                        std::cout << "Do you want to Ace High (h) or Ace Low (l): ";
                        if(testChoice == '0')
                        {
                            std::cin >> choice;
                        }
                        else if(testChoice == 'h')
                            choice = testChoice;
                        else if(testChoice == 'l')
                            choice = testChoice;
                        else
                        {
                            std::cerr << "invalid testChoice argument, leave blank for normal program or choose, h or l, for test mode";
                            exit(1);
                        }
                    }
                    while(!(choice == 'h' || choice == 'l'));
                    
                    if(choice == 'h')
                    {
                        m_player[index].playerScore += 11;
                    }
                    else if(choice == 'l')
                    {
                        m_player[index].playerScore += 1;
                    }
                }
            }; break;
            case PLAYERID_MAX:
            {
                exit(2);
            };
        }
    }
    else
    {
        m_player[index].playerScore += cardValue;
    }
}



void Player::printScore(Player::playerID index)
{
    if(index == PLAYERID_COMPUTER)
    {
        std::cout << "Dealer has score, " << m_player[index].playerScore << ".\n";
    }
    else if(index == PLAYERID_HUMAN)
    {
        std::cout << "You have a score of, " << m_player[index].playerScore << ".\n";
    }
}



int Player::getScore(Player::playerID index)
{
    return m_player[index].playerScore;
}
