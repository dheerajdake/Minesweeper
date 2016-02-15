#include<iostream>
using namespace std;

#include"Header.h"

Minesweeper::Minesweeper()
{
	size = 0;
}

int** Minesweeper::dynamic_arr(int ss)
{
	int **arr;
	arr = new int*[ss];

	for (int a = 0; a < ss; a++)
	{
		arr[a] = new int[ss];
	}
	return arr;
}

void Minesweeper::fill(int **board)
{
	for (int a = 0; a < size; a++)
	{
		for (int b = 0; b < size; b++)
		{
			cin >> board[a][b];
		}
	}
}

void Minesweeper::print(int **board)
{
	for (int a = 0; a < size; a++)
	{
		for (int b = 0; b < size; b++)
		{
			cout << board[a][b] << " ";
		}
		cout << "\n";
	}
}

int **Minesweeper::find(int **arr)
{
	int **arr_f = dynamic_arr(size);
	for (int a = 0; a < size; a++)
	{
		for (int b = 0; b < size; b++)
		{
			//for elements on left corner - 3
			if (((a - 1) < 0) && ((b - 1 < 0)))
			{
				arr_f[a][b] = arr[a][b + 1] + arr[a + 1][b] + arr[a + 1][b + 1];
			}
			else if (((a - 1) < 0) && ((b - 1) >= 0))
			{
				//if its the last element of the row - 3
				if ((b == size - 1) && (a == 0))
				{
					arr_f[a][b] = arr[a][b - 1] + arr[a + 1][b - 1] + arr[a + 1][b];
				}
				//middle elements - 5
				else
				{
					arr_f[a][b] = arr[a][b - 1] + arr[a][b + 1] + arr[a + 1][b - 1] + arr[a + 1][b] + arr[a + 1][b + 1];
				}
			}
			else if (((a - 1) >= 0) && ((b - 1) < 0))
			{
				//first element of the row - 3
				if (a == size - 1)
				{
					arr_f[a][b] = arr[a - 1][b] + arr[a - 1][b + 1] + arr[a][b + 1];
				}
				//middle elements - 5
				else
				{
					arr_f[a][b] = arr[a - 1][b] + arr[a - 1][b + 1] + arr[a][b + 1] + arr[a + 1][b] + arr[a + 1][b + 1];
				}
			}
			else if (((a - 1) >= 0) && ((b - 1) >= 0))
			{
				//last element of the array - 3
				if ((b == size - 1) && (a == size - 1))
				{
					arr_f[a][b] = arr[a - 1][b - 1] + arr[a - 1][b] + arr[a][b - 1];
				}
				//middle elements - 5
				else if (b == size - 1)
				{
					arr_f[a][b] = arr[a - 1][b - 1] + arr[a - 1][b] + arr[a][b - 1] + arr[a + 1][b - 1] + arr[a + 1][b];
				}
				//middle elements - 5
				else if (a == size - 1)
				{
					arr_f[a][b] = arr[a][b - 1] + arr[a][b + 1] + arr[a - 1][b - 1] + arr[a - 1][b] + arr[a - 1][b + 1];
				}
				//center elements - 8
				else
				{
					arr_f[a][b] = arr[a - 1][b - 1] + arr[a - 1][b] + arr[a - 1][b + 1] + arr[a][b - 1] + arr[a][b + 1] + arr[a + 1][b - 1] + arr[a + 1][b] + arr[a + 1][b + 1];
				}
			}
		}
	}
	return arr_f;
}
