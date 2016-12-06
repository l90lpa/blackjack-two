//
//  player.hpp
//  blackjack-two
//
//  Created by Liam on 05/12/2016.
//  Copyright © 2016 Liam. All rights reserved.
//

#ifndef player_hpp
#define player_hpp

#include <array>
#include <iostream>

class Player
{
public:
    enum playerID
    {
        PLAYERID_COMPUTER = 0,
        PLAYERID_HUMAN,
        PLAYERID_MAX
    };
    struct playerInfo
    {
        short playerScore;
        playerID playerIndex;
    };
private:
    std::array<playerInfo, 2> m_player;
public:
    Player();
    
    void addScore(playerID index, int cardValue, char testChoice = '0');
    
    void printScore(playerID index);
    
    int getScore(playerID index);
};

#endif /* player_hpp */
