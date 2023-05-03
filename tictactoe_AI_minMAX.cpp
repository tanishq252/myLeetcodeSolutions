#include <bits/stdc++.h>
using namespace std;

char AIMarker = 'x', humanMarker = 'o';

char board[3][3] = {
	{' ', ' ', ' '},
	{' ', ' ', ' '},
	{' ', ' ', ' '}};

char indBoard[3][3] = {
	{'1', '2', '3'},
	{'4', '5', '6'},
	{'7', '8', '9'}};

bool isMovesLeft(char board[3][3])
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (board[i][j] == ' ')
				return true;
	return false;
}

int evaluate(char b[3][3])
{
	for (int row = 0; row < 3; row++)
	{
		if (b[row][0] == b[row][1] && b[row][1] == b[row][2])
		{
			if (b[row][0] == AIMarker)
				return +10;
			else if (b[row][0] == humanMarker)
				return -10;
		}
	}

	for (int col = 0; col < 3; col++)
	{
		if (b[0][col] == b[1][col] && b[1][col] == b[2][col])
		{
			if (b[0][col] == AIMarker)
				return +10;
			else if (b[0][col] == humanMarker)
				return -10;
		}
	}

	if (b[0][0] == b[1][1] && b[1][1] == b[2][2])
	{
		if (b[0][0] == AIMarker)
			return +10;
		else if (b[0][0] == humanMarker)
			return -10;
	}

	if (b[0][2] == b[1][1] && b[1][1] == b[2][0])
	{
		if (b[0][2] == AIMarker)
			return +10;
		else if (b[0][2] == humanMarker)
			return -10;
	}

	return 0;
}

int minimax(char board[3][3], int depth, bool isMax)
{
	int score = evaluate(board);
	if (score == 10)
		return score;
	if (score == -10)
		return score;
	if (isMovesLeft(board) == false)
		return 0;

	if (isMax)
	{
		int best = -1000;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (board[i][j] == ' ')
				{
					board[i][j] = AIMarker;
					best = max(best, minimax(board, depth + 1, !isMax));
					board[i][j] = ' ';
				}
			}
		}
		return best-depth;
	}

	else
	{
		int best = 1000;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (board[i][j] == ' ')
				{
					board[i][j] = humanMarker;
					best = min(best, minimax(board, depth + 1, !isMax));
					board[i][j] = ' ';
				}
			}
		}
		return best+depth;
	}
}

pair<int, int> findBestMove(char board[3][3])
{
	int bestVal = -1000;
	pair<int, int> bestMove;
	bestMove.first = -1;
	bestMove.second = -1;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == ' ')
			{
				board[i][j] = AIMarker;
				int moveVal = minimax(board, 0, false);
				board[i][j] = ' ';
				if (moveVal > bestVal)
				{
					bestMove.first = i;
					bestMove.second = j;
					bestVal = moveVal;
				}
			}
		}
	}

	return bestMove;
}

void printBoard(char board[3][3])
{
	cout<<"AI marker: 'x'\nYour marker: 'o'\n";
	cout<<"\n";
    cout<<"---------------\n";
	for (int i = 0; i < 3; i++)
	{
        cout<<" | ";
		for (int j = 0; j < 3; j++)
		{
			cout << board[i][j] << " | ";
		}
		cout << "\n";
        cout<<"---------------\n";
	}
	cout << "\n";
}

void computerMove()
{
	pair<int, int> bestMove = findBestMove(board);
	board[bestMove.first][bestMove.second] = 'x';
	cout << "Board after AI move:\n";
	printBoard(board);
}

void playerMove()
{
	cout << "Enter the position from 1-9 where you want to place the marker: \n";
	int x;
	cin >> x;
	if(x<1 or x>9){
		cout<<"The position is invalid, please enter a position between 1-9 as per the index table!\n";
		printBoard(indBoard);
		// printBoard(board);
		playerMove();
		return;
	}
	int i = (x - 1) / 3, j = (x - 1) % 3;
	if (board[i][j] != ' ')
	{
		cout << "Sorry the provided position is already occupied! Please enter the empty position!\n";
		playerMove();
		return;
	}
	board[i][j] = 'o';
	cout << "Board after player move:\n";
	printBoard(board);
}

bool checkWinner()
{
	if (board[0][1] == board[0][2] and board[0][1] == board[0][0] and board[0][0] != ' ')
		return true;
	if (board[1][1] == board[1][2] and board[1][1] == board[1][0] and board[1][1] != ' ')
		return true;
	if (board[2][1] == board[2][2] and board[2][1] == board[2][0] and board[2][2] != ' ')
		return true;
	if (board[0][0] == board[1][0] and board[1][0] == board[2][0] and board[0][0] != ' ')
		return true;
	if (board[0][1] == board[1][1] and board[1][1] == board[2][1] and board[1][1] != ' ')
		return true;
	if (board[0][2] == board[1][2] and board[1][2] == board[2][2] and board[2][2] != ' ')
		return true;
	if (board[0][0] == board[1][1] and board[1][1] == board[2][2] and board[1][1] != ' ')
		return true;
	if (board[0][2] == board[1][1] and board[1][1] == board[2][0] and board[1][1] != ' ')
		return true;
	return false;
}

bool checkDraw()
{
	for (auto &i : board)
	{
		for (auto &j : i)
		{
			if (j == ' ')
				return false;
		}
	}
	return true;
}

int main()
{
	cout << "Welcome to the tic tac toe game!\nPlayer marker is 'o' and computer marker is 'x'\n\n";

	cout << "The following are the indices of the tic tac toe game, please follow those while playing the game!\nThe player goes first!!!\n\n";
	// cout<<""
	printBoard(indBoard);

	string move = "p";

	while (true)
	{

		if (checkDraw())
		{
			cout << "OOPS! the game has been drawn better luck next time player!\n";
			break;
		}

		if (move == "p")
		{
			playerMove();
			if (checkWinner())
			{
				cout << "Yo winner you just defeated AI, congrats!!!";
				break;
			}
			move = "c";
		}

		if (move == "c")
		{
			computerMove();
			if (checkWinner())
			{
				cout << "AI has just beaten you, better luck next time player!!!";
				break;
			}
			move = "p";
		}
	}
	return 0;
}
