#include<iostream>
using namespace std;

class Minesweeper
{
public:
	int size;
	Minesweeper();
	int **dynamic_arr(int ss);
	void print(int **board);
	void fill(int **board);
	int **find(int **board);
};