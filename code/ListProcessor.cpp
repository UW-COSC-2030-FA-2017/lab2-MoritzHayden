// ListProcessor.cpp

//Hayden Moritz
//COSC 2030 - Lab02

// tom bailey   1540  30 sep 2011

// tom bailey   1030  27 jan 2012
// Exercise the List class with verbose Node constructor
//   and destructor.

#include "LinkedList.h"


int main()
{
	List cows;
	cout << "cows list  :  " << cows << endl << endl;

	cows.insertAsFirst(1.23);
	cows.insertAsFirst(2.34);
	cout << "cows list  :  " << cows << endl;
	cout << "Size of cows: " << cows.size() << endl;
	cout << "Sum of cows: " << cows.sum() << endl;
	cows.insertAsFirst(4.22);
	cout << "cows list  :  " << cows << endl;
	cout << "Size of cows: " << cows.size() << endl << endl;
	cout << "Sum of cows: " << cows.sum() << endl;
	

	cows.removeFirst();
	cout << "cows list  :  " << cows << endl;
	cout << "Sum of cows: " << cows.sum() << endl << endl;

	List horses(cows);
	cout << "cows list  :  " << cows << endl;
	cout << "horses list:  " << horses << endl << endl;

	horses.removeFirst();
	horses.insertAsFirst(5.67);
	cows.insertAsFirst(6.78);
	cout << "cows list  :  " << cows << endl;
	cout << "horses list:  " << horses << endl;
	cout << "Sum of cows: " << horses.sum() << endl;
	cout << "Sum of horses: " << horses.sum() << endl;
	cows.insertAsLast(2);
	cout << "Cows list: " << cows << endl << endl;

	List pigs;
	cout << "cows list  :  " << cows << endl;
	cout << "horses list:  " << horses << endl;
	cout << "pigs list  :  " << pigs << endl << endl;

	pigs = cows;
	cout << "cows list  :  " << cows << endl;
	cout << "horses list:  " << horses << endl;
	cout << "pigs list  :  " << pigs << endl << endl;

	pigs = horses;
	cout << "cows list  :  " << cows << endl;
	cout << "horses list:  " << horses << endl;
	cout << "pigs list  :  " << pigs << endl << endl;

	cout << "End of code" << endl;

	system("pause");
	return 0;
}
