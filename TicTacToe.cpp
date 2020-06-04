#include<iostream>
using namespace std;
class tic
{
private:

	char **arr;
	int input;
	int size;

public:
	tic();
	void makearray(); // takes dimentions of array
	void turn();
	void validity(int&, int&);
	bool winner();
	void print();

};
tic::tic()
{
	input = 0;
	size = 0;
}
void tic::makearray()
{
	int k = 0;

	cout << "Enter size of tic-tac-toe ";
	cin >> k;
	size = k;

	arr = new char *[size];
	for (int i = 0; i < size; i++)
		arr[i] = new char[size];    // 2D array created

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			arr[i][j] = '_';           // Array initialized 
	}
}
void tic::turn()
{
	int k=0;
	int row = 0;
	bool result = false;
	int limit = 0;
	print();
	while (1==1) // infinite loop
	{
		row = 0;
		cout << "Player 1 turn : ";
		cin >> k;  // input
		k--;
		while (k >= size*size)
		{
			cout << "Value bigger than board size, input again : \n";
			cin >> k;       // if value exceeds the board size
			k--;
		}
		
		while (k >= size)
		{
			k =  k- size;
			row++;
		}
		validity(row, k);  // checking the move
		arr[row][k] = 'X'; // updating
		
		system("cls");   // removes previous screen
		print();           // printing
		result = winner();  //winner
		limit++;

		if (result == true || limit == size*size)
			break;
		//--------------------------------------------
		cout << "Player 2 turn : ";
		cin >> k;  // input
		k--;
		while (k >= size*size)
		{
			cout << "Value out of bound\n";
			cin >> k;			 // if value exceeds the board size
			k--;
		}
		row = 0;
		while (k >= size)
		{
			k = k - size;
			row++;
		}
		validity(row, k);   // validity check
		arr[row][k] = 'O';  // updating array
		system("cls");   // removes previous screen
		print();           // printing
		result = winner();  // winner check
		
		limit++;
		if (result == true || limit == size*size)
			break;
	}
}
void tic::validity(int& i, int& j)
{
	int p = 0;
	
	while (arr[i][j] == 'X' || arr[i][j] == 'O')
	{
		i = 0;
		cout << "Space already occupied \n Enter new Value : ";
		cin >> j;
		j--;
		p = j;
		while (j >= size)
		{
			j = j - size;
			i++;
		}

	}
	return;
}
bool tic::winner()
{
	int q = 0;
	int k = 0;
	int count = 0;
	int t = 0;
	//------------- row check----------------

	for (int i = 0; i < size; i++)
	{
		for (int l = 0; l < size; l++)
		{
			if (arr[i][0] == 'X' || arr[i][0] == 'O')
			{
				if (arr[i][0] == arr[i][l])
					count++;
			}
		}
		if (count == size)
		{
			if (arr[i][0] == 'X')
			{
				cout << "Player 1 wins \n";
			}
			else cout << "Player 2 wins \n";
			return true;
		}
		count = 0;
		

	}
	//-------------column check------------------
	for (int i = 0; i < size; k++, i++)
	{

		while (t<size)
		{
			if (arr[0][i] == 'X' || arr[0][i] == 'O')// we are checking the col so row will remain zero
			{
				if (arr[0][k] == arr[q][i])
					count++;
			}
			t++;
			q++;
		}
		if (count == size)
		{
			if (arr[i][k] == 'X')
			{
				cout << "Player 1 wins \n";
			}
			else cout << "Player 2 wins \n";
			return true;
		}

		q = 0;
		t = 0;
		count = 0;
	}
	k = 0;
	count = 0;
	// --------Diagnoal---Primary--------------

	for (int j = 0; j < size; j++)
	{
		if (arr[j][j] == 'X' || arr[j][j] == 'O')  // check on board
			if (arr[0][0] == arr[j][j])
				count++;
	}
	if (count == size)
	{
		if (arr[0][0] == 'X')
		{
			cout << "Player 1 wins \n";
		}
		else cout << "Player 2 wins \n";
		return true;
	}
	count = 0;
	// -------Diagnoal -- Secondary---------------
	int r = 0;
	int c = size - 1;
	int i=r;
	int j = c;
	while(t<size)
	{
		
			if (arr[r][c] == 'X' || arr[r][c] == 'O')
				if (arr[r][c] == arr[i++][j--])
					count++;
		
		t++;
	}

	if (count == size)
	{
		if (arr[0][size-1] == 'X')
		{
			cout << "Player 1 wins \n";
		}
		else cout << "Player 2 wins \n";
		return true;
	}
		return false;
}
void tic::print()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			cout << arr[i][j] << "  ";
		cout << endl << endl;
	}

}
/*bool TOSS(int opt)
{
int a = 0;
a = rand() % 1;
if (opt == a)
return true;
return false;
}*/
void main()
{
	//int k = 0;
	/*int opt=0;
	cout << "PLayer one please selct '1' for heads and '0' for tail";
	cin >> opt;
	if (TOSS(opt))
	{
	cout << "PlAYER ONE TURN";
	}
	else
	{
	cout << "PlAYER TWO TURN";
	}
	*/
	tic t1;
	t1.makearray();
	t1.turn();
	system("pause");
}