/*
    PIC 10A Homework 6, Player.h
    Author: Damien Ha
    Date: 11/17/2021
*/

#ifndef Player_h
#define Player_h
#include <string>

using namespace std;

class Player
{
    public:
        Player(); // default constructor
        Player(string myname, int mystamina, int mybattle);
        string getName();
        int getHealth();
        int getBattle();
        int getWin();
        bool battle(Player& enemy);
        bool game(Player& enemy);
    /*
     Specify public interface
     @param getName, getHealth, getBattle, getWin: getter functions to retrieve data
     @param battle: member function, finds a winner of a battle between player an enemy
     @param game: member function, finds a winner of full game between player an enemy
     */
    
    private:
        string name;
        int health;
        int n_battle;
        int n_win;
    /* Declare data fields of class, kept private
     @param name: name of the player
     @param health: remaining health points
     @param n_battle: number of remaining battles
     @param n_win: number of battles that the player has won
     */
};

#endif /* Player_h */
