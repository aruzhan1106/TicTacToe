#include <iostream>
#include "Environment.h"
using namespace std;

int main()
{
    Environment game;
    cout << "WELCOME, PLAYER" << endl;
    cout << "\nWould you like to play against another player or a bot?" << endl;
    cout << "\n1. Another player\n2. Bot" << endl;
    int playerChoice;
    cin >> playerChoice;
    switch (playerChoice) {
    case 1:
        game.playAgainstPlayer();
        break;
    case 2: 
        game.playAgainstBot();
        break;
    default: 
        cout << "Invalid input";
        return 0;
    }
}