#include <iostream>
#include <string>   
#include <windows.h> 
#include "DigitalScales.h"
using namespace std;
#pragma once 

class Iterator
{
public:
	Iterator(void);
	Iterator(DigitalScales* ctr);
	~Iterator(void);
	Iterator(const Iterator& ctr);
	Iterator& operator = (const DigitalScales* ctr);


	Iterator& operator += (const int& ctr);
	Iterator& operator -= (const int& ctr);
	DigitalScales& operator * (void);
	DigitalScales* operator -> (void);
	DigitalScales& operator [] (const int& ctr);

	Iterator& operator ++ (void);
	Iterator operator ++ (int);
	Iterator& operator -- (void);
	Iterator operator -- (int);


	bool operator == (const Iterator& rhs);
	bool operator != (const Iterator& rhs);
	bool operator > (const Iterator& rhs);
	bool operator < (const Iterator& rhs);
	bool operator >= (const Iterator& rhs);
	bool operator <= (const Iterator& rhs);

protected:
	DigitalScales* _ctr;
};


