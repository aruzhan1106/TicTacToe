#include "Environment.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

void Environment::shuffleMoves() {
	srand(time(NULL));
	for (int i = 0; i < 9; i++) {
		moves[i] = i+1;
	}
	random_shuffle(moves, moves + 9);
}
void Environment::playAgainstBot() {
	cout << "Player's marker is X.\nComputer's marker is O." << endl;
	shuffleMoves();
	displayBoard();
	int moveCount = 0;
	for (int i = 0; i < 9; i++) {
		if (currentPlayer == 1) {
			cout << "\nIt's player's turn. Enter square number: " << endl;
			int squareNumber;
			cin >> squareNumber;
			if (squareNumber < 1 || squareNumber>9) {
				cout << "Invalid slot number! Try another slot!";
				i--;
				continue;
			}
			if (!makeAMove(squareNumber)) {
				cout << "That slot is occupied! Try another slot!";
				i--;
				continue;
			}
			displayBoard();
			playerWinner = checkWin();
			if (playerWinner == 1) {
				cout << "\nPlayer 1 won! Congratulations!";
				break;
			}
			if (playerWinner == 2) {
				cout << "\nComputer won. Better luck next time.";
				break;
			}
			changePlayerAndMarker();
		}
		else if (currentPlayer == 2) {
			cout << "\nIt's computer's turn." << endl;
			bool canComputerMove;
			for (int i = 0; i < 9; i++) {
				canComputerMove = makeAMove(moves[i]);
				if (canComputerMove) break;
			}
			displayBoard();
			playerWinner = checkWin();
			if (playerWinner == 1) {
				cout << "\nPlayer 1 won! Congratulations!";
				break;
			}
			if (playerWinner == 2) {
				cout << "\nComputer won. Better luck next time.";
				break;
			}
			changePlayerAndMarker();
		}
	}
	if (playerWinner == 0) {
		cout << "\nIt's a tie!" << endl;
	}
}
void Environment::playAgainstPlayer() {
	cout << "Player 1's marker is X.\nPlayer 2's marker is O" << endl;
	displayBoard();
	for (int i = 0; i < 9; i++) {
		cout << "\nIt's player " << currentPlayer << "'s turn. Enter square number: " << endl;
		int squareNumber;
		cin >> squareNumber;
		if (squareNumber < 1 || squareNumber>9) {
			cout << "Invalid slot number! Try another slot!";
			i--;
			continue;
		}
		if (!makeAMove(squareNumber)) {
			cout << "That slot is occupied! Try another slot!";
			i--;
			continue;
		}
		displayBoard();
		playerWinner = checkWin();
		if (playerWinner == 1) {
			cout << "\nPlayer 1 won! Congratulations!";
			break;
		}
		if (playerWinner == 2) {
			cout << "\nPlayer 2 won! Congratulations!";
			break;
		}
		changePlayerAndMarker();
	}
	if (playerWinner == 0) {
		cout << "\nIt's a tie!" << endl;
	}
}

void Environment::changePlayerAndMarker() {
	if (currentMarker == 'X') currentMarker = 'O';
	else currentMarker = 'X';
	if (currentPlayer == 1) currentPlayer = 2;
	else currentPlayer = 1;

}
void Environment::displayBoard() {
	cout << " "<<gameBoard[0][0] << " | " << gameBoard[0][1] << " | " << gameBoard[0][2] << endl;
	cout << setw(13) << setfill('-');
	cout << "\n " << gameBoard[1][0] << " | " << gameBoard[1][1] << " | " << gameBoard[1][2] << endl;
	cout << setw(13) << setfill('-');
	cout << "\n " << gameBoard[2][0] << " | " << gameBoard[2][1] << " | " << gameBoard[2][2] << endl;
}
bool Environment::makeAMove(int square) {
	int row, column;
	if (square % 3 == 0) {
		row = square / 3 - 1;
		column = 2;
	}
	else {
		row = square / 3;
		column = (square % 3) - 1;
	}
	if (gameBoard[row][column] != 'X' && gameBoard[row][column] != 'O') {
		gameBoard[row][column] = currentMarker;
		return true;
	}
	return false;
}
int Environment::checkWin() {
	for (int i = 0; i < 3; i++) {
		if (gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][1] == gameBoard[i][2]) return currentPlayer;
		if (gameBoard[0][i] == gameBoard[1][i] && gameBoard[1][i] == gameBoard[2][i]) return currentPlayer;
	}
	if (gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2]) return currentPlayer;
	if (gameBoard[0][2] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][0]) return currentPlayer;
	return 0;
}