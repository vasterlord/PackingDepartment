#pragma once
#include "RealNumber.h" 
#include <iostream>
#include <string>   
#include <windows.h> 
#include <math.h>  
#include <iomanip> 
using namespace std;
class DigitalScales : public RealNumber
{ 
private: 
	double _weightError; 
	double _oneCost; 
	double _commonCost;
public:
	DigitalScales(); 
	DigitalScales(double minNumber, double maxNumber, double number, double weightError, double oneCost, double commonCost); 
	void SetWeightError();
	void SetOneCost();
	void SetCommonCost();

	double GetWeightError();
	double GetOneCost();
	double GetCommonCost(); 
	 
	double Cost();
	  
	void Init()override;
	void Show()override;

	virtual ~DigitalScales();
};

