//
// Instructor: Sai-Keung WONG
// Email:	cswingo@cs.nctu.edu.tw
//			wingo.wong@gmail.com
//
// National Chiao Tung University, Taiwan
// Computer Science
// Date: 2019/02/25
//
#include "mySystem_SineCosineFunction.h"
#include <iostream>
#include <math.h>

using namespace std;

namespace {
	//minimum number of sample points
#define MIN_NUM_SAMPLES 2

	//default number of sample points
#define DFT_NUM_SAMPLES 100  
};

SINECOSINE_FUNCTION::SINECOSINE_FUNCTION()
{
	x0 = -20.0;
	x1 = 20.0;
	mNumSamples = DFT_NUM_SAMPLES;
	a = b = 1;
}

void SINECOSINE_FUNCTION::increaseA(double increasedAmount)
{
	a += increasedAmount;

}

void SINECOSINE_FUNCTION::decreaseA(double decreasedAmount)
{
	a -= decreasedAmount;
}

void SINECOSINE_FUNCTION::increaseB(double increasedAmount)
{
	b += increasedAmount;

}

void SINECOSINE_FUNCTION::decreaseB(double decreasedAmount)
{
	b -= decreasedAmount;
}

void SINECOSINE_FUNCTION::increaseSampleNum(int increasedAmount)
{
	mNumSamples += increasedAmount;
}

void SINECOSINE_FUNCTION::decreaseSampleNum(int decreasedAmount)
{
	if (mNumSamples - decreasedAmount >= 10) {
		mNumSamples -= decreasedAmount;
	}
	else {
		mNumSamples = 10;
	}
}

//
// reset
void SINECOSINE_FUNCTION::reset()
{
	a = b = 1;
}

//
//Show the system name
//Ask to input a, b
//Ask to input the range of x in [-10, 10]
//Ask to input the number of sample points
//
void SINECOSINE_FUNCTION::askForInput()
{
	cout << "SINECOSINE_FUNCTION" << endl;

	// Input a and b
	cout << "Input the coeffients, a and b: a cos(b*x)" << endl;
	cin >> a >> b;

	// Input range of x
	do {
		cout << "Input the range of x [-10, 10]: " << endl;
		cin >> x0 >> x1;
	} while ((x0 < -10 || x0 > 10) || (x1 < -10 || x1 > 10));

	// Input num of sample points
	do {
		cout << "Input the number of sample points [2, 100]: " << endl;
		cin >> mNumSamples;
	} while (mNumSamples < MIN_NUM_SAMPLES || mNumSamples > 100);
}
//
// Get the range of x
// by-reference
//(x0, x1) formal parameters
// x0: minimum x 
// x1: maximum x
//
void SINECOSINE_FUNCTION::getRangeOfX(double &x0, double &x1) const
{
	//Return the range of x in x0 and x1.
	x0 = this->x0;
	x1 = this->x1;
}

//
//Return the number of samples
//
int SINECOSINE_FUNCTION::getNumOfSamples() const
{
	return mNumSamples;
}

//
// Get the function value for x
//
double SINECOSINE_FUNCTION::getValue(double x) const
{
	// a cos(b*x)
	return a * cos(b * x);
}
// CODE: 2019/02/25. Do not delete this line.