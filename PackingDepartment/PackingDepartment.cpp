// PackingDepartment.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>    
#include <windows.h> 
#include <math.h>  
#include <iomanip>   
#include <conio.h> 
#include "PackingShop.h"
using namespace std;

int main()
{
	int choose = 1;
	int number = 0; 
	double commonWeight = 0;
	string choice = "y";
	int size = 1;
	cout << " Input size packing shop :" << endl;
	cin >> size;
	PackingShop packingShop(size);
	while (choice == "y")
	{
		cout << " 1 - Input products" << endl; 
		cout << " 2 - Output one product" << endl; 
		cout << " 3 - Output packed products" << endl; 
		cout << " 4 - Output all products" << endl;
		cout << " 5 - Get total price of packed products " << endl; 
		cout << " 6 - Get total price of all products " << endl; 
		cout << " 7 - Get total weight error " << endl;
		cout << "Your choice: "; cin >> choose;
		cout << endl;
		switch (choose)
		{
		case 1:
			packingShop.InputProducts();
			break;
		case 2:
			cout << " Input index of product :" << endl;
			cin >> number;
			packingShop.operator[](number).Show();
			break;
		case 3:
			cout << " Input common weight value :" << endl;
			cin >> commonWeight;
			packingShop.OutputPrepackProducts(commonWeight);
			break;
		case 4:
			packingShop.OutputProducts();
			break;
		case 5:
			cout << " Input common weight value :" << endl;
			cin >> commonWeight;
			cout << " Total price of packed products = " << packingShop.PrepackCost(commonWeight) << endl;
			break;
		case 6:
			cout << " Total price of all products = " << packingShop.TotalProductsCost() << endl;
			break;
		case 7:
			cout << " Total weight error = " << packingShop.TotalError() << endl;
			break;
		default:
			break;
		}
		cout << "Press 'y' if you want to continue "; cin >> choice;
	}
	_getch();
	return 0;
}


