#include<iostream>
using namespace std;
#include"Header.h"

int main()
{
	cout << "-----------------COUNTING NEAREST NEIGHBOURS-----------------\n";
	Minesweeper obj;
    int size;
	cout << "Enter the size of the array: ";
	cin >> obj.size;
	
	
	//Create a dynamic array
	int **arr = obj.dynamic_arr(obj.size);
	

	//fill the array
	obj.fill(arr);


	//print the array
	cout << "\nThe array entered is:\n";
	obj.print(arr);

	//find the neighbours
	//The possible neighbour combinations
	//		arr[a-1][b-1] | arr[a-1][b] | arr[a-1][b+1]			
	//      arr[a][b-1]   | arr[a][b]   | arr[a][b+1]
	//		arr[a+1][b-1] | arr[a+1][b] | arr[a+1][b+1]
	//
	// Let's consider all the cases,
	// 1. If the element is a corner element, it will have 3 neighbours
	// 2. If the element is a middle element, it will have 8 neighbours
	// 3. If the element is on the side apart from the corner elements, it will have 5 neighbours
	
    // There are 4 cases to be considered. These are listed below.

	//Search each element
	int **arr_f = obj.find(arr);

	
	//print the array
	cout << "\nThe number of neighbours are:\n";
	obj.print(arr_f);

	//deallocate the memory
	delete[] arr_f;
	delete[] arr;

	system("pause");
	return -1;
}