#include "stdafx.h"
#include "RealNumber.h"
#include <iostream>
#include <string>   
#include <windows.h> 
#include <math.h>  
#include <iomanip> 
using namespace std;

RealNumber::RealNumber()
{
	_minNumber = 0;
	_maxNumber = 1000000;
	_number = 0;
}

RealNumber::RealNumber(double minNumber, double maxNumber, double number)
{
	SetMinNumber(minNumber);
	SetMaxNumber(maxNumber);
	SetNumber(number);
}

void RealNumber::SetMinNumber()
{
	cout << " Enter minimum range of number : \n";
	cin >> _minNumber;
}
 
void RealNumber::SetMaxNumber()
{
	cout << " Enter maximum range of number : \n";
	cin >> _maxNumber;
}  
 
void RealNumber::SetMinNumber(double minNumber)
{
	_minNumber = minNumber;
}

void RealNumber::SetMaxNumber(double maxNumber)
{
	_maxNumber = maxNumber;
}
 
bool RealNumber::CheckNumber(double number)  
{ 
	if (number < _minNumber || number >_maxNumber)
	{
		return false;
	} 
	else
	{
		return true;
	}
}
void RealNumber::SetNumber()
{
	cout << " Enter the number : \n"; 
	double number = 0;
	cin >> number; 
	if (CheckNumber(number))
	{
		_number = number;
	} 
	else
	{
		cout << "This value have incorect range! This value setted by default to 0." << endl; 
		_number = 0;
	}
}

void RealNumber::SetNumber(double number)
{
	if (CheckNumber(number))
	{
		_number = number;
	}
	else
	{
		cout << "This value have incorect range! This value setted by default to 0." << endl;
		_number = 0;
	}
}
 
double RealNumber::GetMinNumber()  
{
	return _minNumber;
}  

double RealNumber::GetMaxNumber()
{
	return _maxNumber;
}  

double RealNumber::GetNumber()
{
	return _number;
}

istream& operator >> (istream& is, RealNumber& realNumber)
{
	cout << " Enter minimum range of number : \n";
	cin >> realNumber._minNumber;
	cout << " Enter maximum range of number : \n";
	cin >> realNumber._maxNumber;
	cout << " Enter the number : \n";
	cin >> realNumber._number;
	return is;
}

ostream& operator<<(ostream& os, RealNumber& realNumber)
{
	cout << " Real number = " << realNumber._number << ", minimum number =  " << realNumber._minNumber<< ", maximum number = " << realNumber._maxNumber << endl;
	return os;
}

void RealNumber::Show()
{
	cout << " Real number = " << _number << ", minimum number =  " << _minNumber << ", maximum number = " << _maxNumber << endl;
}

void RealNumber::Init()
{
	SetMinNumber(); 
	SetMaxNumber(); 
	SetNumber();
} 
 
double RealNumber::Cost()
{
	return 0;
}

RealNumber& RealNumber::operator=(const RealNumber& realNumber)
{
	this->_minNumber = realNumber._minNumber; 
	this->_maxNumber = realNumber._maxNumber; 
	this->_number = realNumber._number;
	return *this;
}

RealNumber& RealNumber::operator()()
{
	this->_number = round(_number);
	return *this;
} 
 
RealNumber& RealNumber::operator[](double precision)
{ 
	precision = round(precision);
	this->_number = fmod(_number, precision);
	return *this;
}

RealNumber& RealNumber::operator+(double number)
{  
	double nextNumber = _number + number;
	SetNumber(nextNumber);
	return *this;
} 
 
RealNumber& RealNumber::operator-(double number)
{
	double nextNumber = _number - number;
	SetNumber(nextNumber);
	return *this;
} 
 
RealNumber& RealNumber::operator*(double number)
{
	int nextNumber = _number * number;
	SetNumber(nextNumber);
	return *this;
} 
 
RealNumber& RealNumber::operator/(double number)
{
	double nextNumber = _number / number;
	SetNumber(nextNumber);
	return *this;
}  

RealNumber::~RealNumber()
{ 
	OutputDebugString(L"RealNumber destructor worked");
}
