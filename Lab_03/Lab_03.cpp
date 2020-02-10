/*
 * Edward Cruz, Lab 03
 * 02/03/2020
 *  
*/

#include <iostream>
#include "playerType.h"

playerType player1("Mario");
playerType player2("Luigi");
bool playerTwo = false;

void main_menu();
void add_coins_plus();
void random_item();
void special_check();
void add_player_two();
void fake_death();

int main()
{
    char more;
    int input;

    do {
        std::cout << "\nWelcome to Mario data testing menu";
        do {

            main_menu();
            std::cin >> input;
            
            switch(input) {
                case 1:
                    add_coins_plus();
                break;
                case 2:
                    random_item();
                break;
                case 3:
                    special_check();
                break;
                case 4:
                    add_player_two();
                break;
                case 99:
                    fake_death();
                break;
                default: std::cout << "\n\nPlease Input a number option from the main menu.";
            }


        } while (player1.get_lives() > 0 || input == 99);  
        std::cout << "\n\n\t\tContinue (Y/N) ? ";
        std::cin  >> more;  
    } while (more == 'y' || more == 'Y');

    return 0;
}

void main_menu() {
    std::cout << "\n\n\n1: Add coins to Player(s).";
    std::cout << "\n2: Run random item drop for Question mark block.";
    std::cout << "\n3: Check to see if Player(s) has special item active.";
    std::cout << "\n4: Add a second Player.";
    std::cout << "\n99: Fake Player's death to get Game Over screen.";
    std::cout << "\n Please enter an option from above: ";
}

void add_coins_plus() {
    int coins;
    std::cout << "\n\nCurrently " << player1.get_name() << " has " << player1.get_coins() 
              << " coins and " << player1.get_lives() << " lives.";
    std::cout << "\nHow many coins would you like to add to Player 1: ";
    std::cin  >> coins;
    player1.set_coins(coins);
    std::cout << player1.get_name() << " now has " << player1.get_coins() 
              << " coins and " << player1.get_lives() << " lives." << std::endl;
    if (playerTwo) {
        std::cout << "\n\nCurrently " << player2.get_name() << " has " << player2.get_coins() 
              << " coins and " << player2.get_lives() << " lives.";
        std::cout << "\nHow many coins would you like to add to Player 2.";
        std::cin  >> coins;
        player2.set_coins(coins);
        std::cout << player2.get_name() << " now has " << player2.get_coins() 
              << " coins and " << player2.get_lives() << " lives." << std::endl;
    }
}

void random_item() {
    player1.get_specialItems();
    std::cout << "\n\nPlayer 1: The item that came out of the block is " << player1.get_special_Item();
    if(playerTwo) {
        player2.get_specialItems();
        std::cout << "\nPlayer 2: The item that came out of the block is " << player1.get_special_Item();
    }
}

void special_check() {
    std::cout << "\n\nPlayer 1: " << player1.get_name() << " has " 
              << player1.get_special_Item() << " as their current special.";
    
    if(playerTwo) {
        std::cout << "\n\nPlayer 2: " << player2.get_name() << " has " 
                  << player2.get_special_Item() << " as their current special.";
    }
}

void add_player_two() {
    if (!playerTwo)
        playerTwo = true;
    else std::cout <<"\n\nPlayer 2 is already active and their name is " << player2.get_name();
}

void fake_death() {
    (&player1)->~playerType();
    new (&player1) playerType("Mario");
    if (playerTwo) {
        (&player2)->~playerType();
    new (&player2) playerType("Luigi");
    }
    
    std::cout << "\n\nGame Over";

}