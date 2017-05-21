#include "stdafx.h"
#include "PackingShop.h"
#include <iostream>
#include <string>   
#include <windows.h> 
#include <math.h>  
#include <iomanip>  
#include "DigitalScales.h"  
#include "Iterator.h"
using namespace std;

PackingShop::PackingShop()
{
} 
 
PackingShop::PackingShop(int size)
{  
	_size = size;
	_digitalScales = new DigitalScales[size];
}
 
void PackingShop::Sort()
{
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j< _size - 1; j++)
		{
			if (_digitalScales[j].GetNumber()>_digitalScales[j + 1].GetCommonCost())
			{
				DigitalScales temp = _digitalScales[j];
				_digitalScales[j] = _digitalScales[j + 1];
				_digitalScales[j + 1] = temp;
			}
		}
	} 
} 
 
void PackingShop::OutputPrepackProducts(double commonWeight)
{ 
	Sort(); 
	Iterator iter = _digitalScales;
	cout << " Prepack products: " << endl;
	for (int i = 0; i < _size; i++)
	{ 
		if (iter->GetNumber()<=commonWeight)
		{
			iter->Show();
		} 
		else
		{
			break;
		}
		++iter;
	}
} 
 
double PackingShop::PrepackCost(double commonWeight)
{
	Sort();
	Iterator iter = _digitalScales;
	double prepackCost = 0;
	for (int i = 0; i < _size; i++)
	{
		if (iter->GetNumber() <= commonWeight)
		{
			prepackCost = prepackCost + iter->Cost(); 
		}
		else
		{ 
			return prepackCost;
			break;
		}
		++iter;
	} 
	return prepackCost;
}
 
double PackingShop::TotalError()  
{ 
	Iterator iter = _digitalScales; 
	double totalError = 0;
	for (int i = 0; i < _size; i++)
	{ 
		totalError = totalError + iter->GetWeightError();
		++iter;
	}
	return totalError;
} 
 
double PackingShop::TotalProductsCost()
{ 
	Iterator iter = _digitalScales;
	double totalCost = 0;
	for (int i = 0; i < _size; i++)
	{ 
		totalCost = totalCost + iter->Cost();
		++iter;
	}
	return totalCost;
}
 
void PackingShop::InputProducts()  
{ 
	for (int i = 0; i < _size; i++)
	{
		cout << " Input data about product  " << i << endl;
		DigitalScales digitalScales;
		digitalScales.Init();
		_digitalScales[i] = digitalScales;
	}
	cout << " Input data about product ";
} 
 
void PackingShop::OutputProducts()
{
	Iterator iter = _digitalScales;
	cout << " All products: " << endl;
	for (int i = 0; i < _size; i++)
	{ 
		iter->Show();
		++iter;
	}
}  
 
DigitalScales& PackingShop::operator[](int x)
{
	try
	{
		if (x < 0 || x > _size)
		{
			throw(" Incorrect index! ");
		}
		else
		{
			return _digitalScales[x];
		}
	}
	catch (char *str)
	{
		cout << str << endl;
	}
	catch (std::exception ex) {
		cout << " Incorrect index " << endl;
	}
} 

PackingShop::~PackingShop()
{ 
	OutputDebugString(L"DigitalScales destructor worked");
	delete[] _digitalScales;
}
