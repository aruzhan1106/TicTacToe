#pragma once
class Environment
{
public:
	char gameBoard[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
	int moves[9];
	char markerPlayer1 = 'X';
	char markerPlayer2 = 'O';
	char currentMarker = 'X';
	int currentPlayer = 1;
	int playerWinner;
	void displayBoard();
	bool makeAMove(int square);
	int checkWin();
	void playAgainstPlayer();
	void playAgainstBot();
	void changePlayerAndMarker();
	void shuffleMoves();
};

