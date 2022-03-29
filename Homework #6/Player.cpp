/*
    PIC 10A Homework 6, Player.cpp
    Author: Damien Ha
    Date: 11/17/2021
*/

#include<iostream>
#include<ctime>
#include<stdlib.h>
#include"Player.h"

using namespace std;

Player::Player() // default constructor for the class Player
{
    name = "MyPlayer"; // initialize name as MyPlayer
    health = 0; // initialize health as 0
    n_battle = 0; // initialize the number of battles as zero
    n_win = 0; // initialize the number of wins as 0
}

Player::Player(string myname, int myhealth, int mybattles) // explicit parameters for Player
{
    name = myname; 
    health = myhealth;
    n_battle = mybattles;
    n_win = 0;
}

string Player::getName() // getter function, gets name from Player class
{
    return name;
}

int Player::getHealth() // getter function, gets health from Player class
{
    return health;
}

int Player::getBattle() // getter function, gets number of battles from Player class
{
    return n_battle;
}

int Player::getWin() // getter function, gets number of wins from Player class
{
    return n_win;
}

bool Player::battle(Player& enemy) // battle function from the player class
{
    cout << "There are " << n_battle << " battles left." << endl; // tell user how many battles remain
    cout << "You have " << health << " health points left." << endl; // tell user the number of their remaining health points
    
    int playerUsedHealth, enemyUsedHealth; // create integer variables for the health points used by the player and the enemy
    
    if(n_battle == 1)
    {
        enemyUsedHealth = enemy.health; // enemy uses all remaining health for last battle
    }
    else
    {
        enemyUsedHealth = rand() % (enemy.health + 1); // otherwise the enemy uses a random number of health points from 1 to 100
    }
    
    cout << "How many health points do you want to use? "; // prompt user to input health points to use
    cin >> playerUsedHealth; // allow user to input health points to use
    
    cout << name << " choose to use " << playerUsedHealth << " health points." << endl;
    cout << enemy.name << " choose to use " << enemyUsedHealth << " health points." << endl;
    // reveal how much health each person used
    
    health = health - playerUsedHealth;
    enemy.health = enemy.health - enemyUsedHealth;
    // reassignment so that remaining health for both is the difference between previous health and used health
    
    if(playerUsedHealth > enemyUsedHealth)
    {
        cout << name << " wins this battle!" << endl;
        cout << "****************************************************\n";
        n_win++;
        return true;
        // when the player uses more health points, they win the battles
    }
    else
    {
        cout << enemy.name << " wins this battle!" << endl;
        cout << "****************************************************\n";
        enemy.n_win++;
        return false;
        // otherwise, the enemy wins the battle
    }
}

bool Player::game(Player& enemy) // game function from the Player class
{
    for(int i = n_battle; i > 0; i--) // continue game until number of battles runs to 0
    {
        battle(enemy); // implement a battle against the enemy
        n_battle--; // there is one less battle after each round
    }
    if (n_win > enemy.n_win)
    {
        cout << "The final winner is " << name << "." << endl;
        return true;
    }
    // declare the player the winner when they have won more battles
    else
    {
        cout << "The final winner is " << enemy.name << "." << endl;
        return false;
    }
    // declare the enemy the winner when they have won more battles
    return 0;
}
