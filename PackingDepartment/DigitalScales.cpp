#include "stdafx.h"
#include "DigitalScales.h"


DigitalScales::DigitalScales():RealNumber()
{ 
	_weightError = 0.000001;
	_oneCost = 7;
	_commonCost = 10;
}

DigitalScales::DigitalScales(double minNumber, double maxNumber, double number, double weightError, double oneCost, double commonCost) :RealNumber(minNumber, maxNumber, number)
{
	_weightError = weightError;
	_oneCost = oneCost;
	_commonCost = commonCost;
} 
 
void DigitalScales::SetOneCost()
{
	cout << " Enter cost by one product : \n";
	cin >> _oneCost;
}

void DigitalScales::SetCommonCost()
{
	cout << " Enter common cost: \n";
	cin >> _commonCost;
} 
void DigitalScales::SetWeightError()
{
	cout << " Enter weight error : \n";
	cin >> _weightError;
} 
 
double DigitalScales::GetOneCost()  
{ 
	return _oneCost;
}  

double DigitalScales::GetWeightError()
{
	return _weightError;
} 

double DigitalScales::GetCommonCost()
{
	return _commonCost;
}
 
double DigitalScales::Cost()  
{ 
	return GetNumber()*GetOneCost();
}  
void DigitalScales::Show()
{
	cout << " Current weight of product = " << GetNumber() << ", cost per one product " << _oneCost << ", weight error = " << _weightError << ", common cost = " << _commonCost << endl;
}
 
void DigitalScales::Init()  
{ 
	RealNumber::Init(); 
	SetOneCost(); 
	SetWeightError(); 
	SetCommonCost();
}

DigitalScales::~DigitalScales()
{
}
