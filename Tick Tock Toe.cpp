#include <iostream>
using namespace std;
char game[3][3] = {'1','2','3','4','5','6','7','8','9'};
char player='X';
void show()
{
	system("cls");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << game[i][j] << " ";
		}
		cout << endl;
	}
}
void turn()
{
	if (player == 'X')
		player = 'O';
	else
		player = 'X';
}
void input()
{
	int in;
	bool yub;
	cout << "The turn of  player (" << player << ") = ";
	do
	{
		cin >> in;
		if (in <= 3)
		{
			if (game[0][in - 1] != 'X'&& game[0][in - 1] != 'O')
			{
				game[0][in - 1] = player;
				yub = false;
			}
			else
			{
				cout << "The number is already taken choose anther one = ";
				yub = true;
			}
		}
		else if (in>3&&in<7)
		{
			if (game[1][in - 4] != 'X'&& game[1][in - 4] != 'O')
			{
				game[1][in - 4] = player;
				yub = false;
			}
			else
			{
				cout << "The number is already taken choose anther one = ";
				yub = true;
			}
		}
		else
		{
			if (game[2][in - 7] != 'X'&& game[2][in - 7] != 'O')
			{
				game[2][in - 7] = player;
				yub = false;
			}
			else
			{
				cout << "The number is already taken choose anther one = ";
				yub = true;
			}
		}
	} while (yub);
	
}
char win()
{
	for (int i = 0; i < 3; i++)
	{
		if (game[i][0] == player&&game[i][1] == player&&game[i][2] == player)
			return player;
		else if (game[0][i] == player&&game[1][i] == player&&game[2][i] == player)
			return player;
	}
	if (game[0][0] == player&&game[1][1] == player&&game[2][2] == player)
		return player;
	else if (game[0][2] == player&&game[1][1] == player&&game[2][0] == player)
		return player;
	else
		return '/';
}
bool noone()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (game[i][j] != 'X' && game[i][j] != 'O')
				return false;
		}
	}
	return true;
}
int main()
{
	cout << "Tic Tac Toe game let's play \n";
	show();
	while (1)
	{
		input();
		show();
		if (win() == player)
		{
			cout << "The winner is player (" << player << ")" << endl;
			break;
		}
		if (noone())
		{
			cout << "There is no winner" << endl;
			break;
		}
		turn();
	}
	//system("pause");
	return 0;
}