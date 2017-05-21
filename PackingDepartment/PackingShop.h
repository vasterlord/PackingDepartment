#pragma once 
#include <iostream>
#include <string>   
#include <windows.h> 
#include <math.h>  
#include <iomanip>  
#include "DigitalScales.h"  
#include "Iterator.h"
using namespace std;
class PackingShop
{ 
private: 
	int _size; 
	DigitalScales *_digitalScales;
public:
	PackingShop(); 
	PackingShop(int size); 

	void Sort();  

	double PrepackCost(double commonWeight);

	double TotalError(); 

	double TotalProductsCost(); 
	 
	void InputProducts(); 
	 
	void OutputPrepackProducts(double commonWeight);

	void OutputProducts();
	 
	DigitalScales& operator[](int x);

	virtual ~PackingShop();
};

