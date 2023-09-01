#include <iostream>
#include <iomanip>
#define size 15
#define powerConst 0.5

using namespace std;
class block
{
	private:
		double map[size][size] = {
			{1.9 ,1.9 ,1.8 ,1.8 ,1.8 ,1.9 ,1.9 ,1.8 ,1.9 ,1.7 ,1.6 ,1.6 ,1.6 ,1.6 ,1.7},
			{1.9, 1.9, 2.0, 1.9, 1.8, 1.7, 1.7, 2.0, 1.7, 1.8, 2.0, 1.9, 1.8, 1.8, 2.1},
			{2.0, 2.1, 2.2, 2.2, 2.2, 2.3, 2.4, 2.3, 2.1, 1.7, 1.8, 1.8, 2.2 ,2.3, 2.5},
			{2.1, 2.2, 2.7, 2.7, 2.8, 2.8, 2.7, 2.5, 2.3, 2.0, 1.9, 1.8, 1.9 ,2.3, 1.8},
			{2.2, 2.3, 2.8, 3.5, 2.8, 2.7, 2.6, 2.4, 2.4, 2.3, 2.0, 1.9, 1.8 ,2.2, 1.7},
			{2.3, 2.4, 2.7, 2.9, 3.2, 3.0, 2.9, 2.6, 2.3, 2.3, 2.2, 2.3, 2.2 ,1.8, 1.6},
			{2.4, 2.5, 3.6, 3.1, 3.5, 3.3, 3.0, 2.7, 2.3, 2.2, 2.1, 2.1, 1.9 ,1.8, 1.7},
			{2.7, 2.7, 3.0, 3.6, 3.7, 3.1, 2.8, 2.4, 2.7, 2.6, 2.2, 2.4, 2.0 ,1.9, 1.8},
			{2.9, 3.0, 2.8, 3.5, 4.0, 2.9, 2.6, 2.5, 3.0, 2.4, 2.2, 2.1, 2.4 ,2.1, 1.9},
			{2.5, 2.9, 3.1, 3.4, 3.1, 2.8, 2.7, 2.6, 2.8, 2.4, 2.3, 2.2, 2.7 ,1.9, 2.2},
			{2.8, 2.7, 3.0, 3.5, 3.3, 3.2, 3.1, 2.8, 3.0, 2.6, 2.6, 2.2, 2.1 ,2.3, 2.5},
			{2.9, 3.0, 2.9, 3.3, 3.6, 3.5, 3.6, 3.3, 3.9, 3.2, 2.6, 2.3, 2.3 ,3.0, 2.0},
			{2.7, 2.8, 3.0, 2.9, 3.4, 3.0, 3.3, 3.2, 3.9, 3.4, 2.8, 2.7, 2.4 ,2.2, 2.1},
			{2.6, 2.7, 2.8, 2.7, 3.0, 2.8, 3.2, 2.9, 3.1, 3.3, 3.0, 2.7, 2.3 ,2.2, 2.5},
			{2.5, 2.5, 2.6, 2.5, 2.6, 2.7, 3.0, 2.8, 2.8, 3.1, 3.4, 2.9, 2.5 ,2.4, 2.6}
		};
		double transferPower[size][size];
		double hoverPower[size][size];
		double totalPower;
		long int pascal[size][size];
	public:
		block();
		void setPascal();
		int accessPascal(int, int);
		long int waysCount();
		long int Power();
		void setPower();
		long int moves;
};

block::block()
{
		totalPower = 0;
		moves = 30;
}

void block::setPower()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			hoverPower[i][j] = map[i][j];
			transferPower[i][j] = map[i][j];
		}
	}
	totalPower += moves * powerConst;
}

void block::setPascal()
{
	for (int i = 0; i < size; i ++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i == 0)
			{
				pascal[i][j] = 1;
			}
			else if (j == 0)
			{
				pascal[i][j] = 1;
			}
			else
			{
				pascal[i][j] = 0;
			}
			moves++;
		}
	}
	for (int i = 1; i < size; i ++)
	{
		for (int j = 1; j < size; j++)
		{
			pascal[i][j] = pascal[i - 1][j] + pascal[i][j - 1];
		}
	}
}

int block::accessPascal(int i, int j)
{
	return pascal[i][j];
}

long int block::waysCount()
{
	long int sum = 0;
	int j = size - 1;
	for (int i = 0; i < size; i++)
	{
		sum += (pascal[i][j]);
	}
	return sum;
}

long int block::Power()
{
	return totalPower;
}

int main()
{
	block map;
	map.setPascal();
	map.setPower();
	cout << "\x1B[2J\x1B[H";
	string view[size][size];
	//-- View in Terminal
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << "\033[1;106m  ";//<< map.accessPascal(i, j)
		}
		cout << endl;
	}
	cout << endl << "\033[0m";
	cout << "\033[1;36m" << endl;
	cout << "There are " << map.waysCount() << " Ways." << endl;
	cout << "Total Power is : " << map.Power() <<endl;
	return 0;
}
