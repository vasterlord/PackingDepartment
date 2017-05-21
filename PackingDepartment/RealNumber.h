#pragma once 
#include <iostream>
#include <string> 
#include <windows.h> 
#include <math.h>  
#include <iomanip> 
using namespace std; 

class RealNumber
{ 
protected:
	double _minNumber;
	double _maxNumber;
	double _number;
public:
	RealNumber(); 
	RealNumber(double minNumber, double maxNumber, double number);

	void SetMinNumber();
	void SetMaxNumber();
	void SetNumber();

	void SetMinNumber(double minNumber);
	void SetMaxNumber(double maxNumber);
	void SetNumber(double number);

	double GetMinNumber();
	double GetMaxNumber();
	double GetNumber();
	 
	bool CheckNumber(double number); 

	friend istream& operator >> (istream&, RealNumber&);
	friend ostream& operator << (ostream&, RealNumber&);

	RealNumber& operator=(const RealNumber&);
	RealNumber& operator()(); 
	RealNumber& operator[](double precision);
	RealNumber& operator+(double number);
	RealNumber& operator-(double number);
	RealNumber& operator*(double number);
	RealNumber& operator/(double number);
	 
	virtual void Init();
	virtual void Show();  
	virtual double Cost();
	
	virtual ~RealNumber();
};

