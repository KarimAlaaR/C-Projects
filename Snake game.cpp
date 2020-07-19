#include <iostream>
#include <ctime>
using namespace std;
const int rows = 10, columns = 10;
int ships[rows][columns];
int number_of_ships = 10;
void clear()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10;j++)
		{
			ships[i][j] = 0;
		}
	}
}
void show()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout <<"x  ";
		}
		cout << endl;
	}
	cout << "---------------------" << endl;
}
void show_result()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << ships[i][j] << "  ";
		}
		cout << endl;
	}
	cout <<"---------------------"<<endl;
}
void set_ships()
{
	int s = 0, x, y;
	while (s < number_of_ships)
	{
		x = rand() % rows;
		y = rand() % columns;
		if (ships[x][y] != 1)
		{
			ships[x][y] = 1;
			s++;
		}
	}
}
bool atack(int a, int b)
{
	if (ships[a][b] == 1)
	{
		ships[a][b] = 2;
		number_of_ships--;
		return true;
	}
	return false;
}
int main()
{
	srand(time(NULL));
	int x, y;
	char z;
	clear();
	set_ships();
	show();
	show_result();
	while (1)
	{
		cout << "Enter the fucking position nega = ";
		cin >> x >> y;
		if (atack(x, y))
		{
			cout << "will done nega \n";
			cout << "The number of ships is =" << number_of_ships << endl;
			if (number_of_ships==0) break;
		}
		else
		{
			cout << "hahahaha you are really nega" << endl;
			cout << "The number of ships is =" << number_of_ships << endl;
		}
		cout << "Again?(y/n) ";
		cin >> z;
		 if (z == 'n') break;
			
	}
	show_result();
	cout << "The number of ships is =" << number_of_ships << endl;

	//system("pause");
	return 0;
}