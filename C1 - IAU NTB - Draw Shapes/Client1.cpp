#include <iostream>
using namespace std;

//-------- Prototypes -------- 
int shape_Create(int, int);

//-------- Structure --------- 
struct shape {
	int size;
	int side;
};

int main()
{
	struct shape shape;
	start:
	cout<<"Please Enter a Number Between 1 - 6 :\t";
	cin>>shape.side;
	if (shape.side < 7 && shape.side > 0)
	{
		cout<<"Now Enter Size Of Your Shape :\t";
		cin>>shape.size;
	}
	else
	{
		cout<<"- Number "<<shape.side<<" Isn't Between 1 - 6 !!\n\n";
		goto start;
	}
	if (shape.size > 0)
	{
		shape_Create(shape.side,shape.size);
	}
	else
	{
		cout<<"- Size "<<shape.size<<" Is Not Valid !! It Must Be Higher than '0' !\n\n";
		goto start;
	}
	return 0;
}

int shape_Create(int x, int SIZE)
{
	cout<<"Your Shape With Given Number "<<x<<" is :\n\n";
	switch (x)
	{
		//----------- Line -----------
		case 1 : 
			for (int i = 0; i < SIZE; i++)
			{
				cout<<"* ";
			}
			cout<<endl;
		break;
		//---------- angle -----------
		case 2 : 
			for (int i = 0; i < SIZE; i++)
			{
				for (int j = 0; j < SIZE; j++)
				{
					if (i == 0  || i == j )
					{
						cout<<"* ";
					}
					else
					{
						cout<<"  ";
					}
				}
				if (i == 0)
				{
					cout<<"* ";
				}
				cout<<endl;
			}
			cout<<endl;
		break;
		//--------- triangle ---------
		case 3 : 
			for (int i = 0; i < SIZE; i++)
			{
				for (int k = SIZE - i; k > 0; k--)
				{
					cout<<" ";
				}
				for (int j = 0; j < i; j++)
				{
					cout<<"* ";
				}
				cout<<endl;
			}
			cout<<endl;
		break;
		//---------- Square ----------
		case 4 : 
			for (int i = 0; i < SIZE; i++)
			{
				for (int j = 0; j < SIZE; j++)
				{
					if (i == 0 || j == 0 || i == SIZE - 1 || j == SIZE - 1 )
					{
						cout<<"* ";
					}
					else
					{
						cout<<"  ";
					}
				}
				cout<<endl;
			}
			cout<<endl;
		break;
		//--------- Pentagon ---------
		case 5 : 
			for (int i = 1; i <= SIZE; i+=3)
			{
				for (int k = SIZE - i; k > 0; k--)
				{
					cout<<" ";
				}
				for (int j = 0; j < i; j++)
				{
					cout<<"* ";
				}
				cout<<endl;
			}
			for (int a = SIZE; a > SIZE / 2; a--)
			{
				for (int b = SIZE - a; b > 0; b--)
				{
					cout<<" ";
				}
				for (int c = a; c > 0; c--)
				{
					cout<<"* ";
				}
				cout<<endl;
			}
		break;
		//--------- hexagon ---------- 
		case 6 : 
			for (int i = SIZE / 2 + 1; i < SIZE; i++)
			{
				for (int k = SIZE - i; k > 0; k--)
				{
					cout<<" ";
				}
				for (int j = 0; j < i; j++)
				{
					cout<<"* ";
				}
				cout<<endl;
			}
			for (int a = SIZE; a > SIZE / 2; a--)
			{
				for (int b = SIZE - a; b > 0; b--)
				{
					cout<<" ";
				}
				for (int c = a; c > 0; c--)
				{
					cout<<"* ";
				}
				cout<<endl;
			}
		cout<<endl;
		break;
		default : main();
	}
	return 0;
}