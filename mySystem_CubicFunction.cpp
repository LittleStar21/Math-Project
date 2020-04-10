//
// Instructor: Sai-Keung WONG
// Email:	cswingo@cs.nctu.edu.tw
//			wingo.wong@gmail.com
//
// National Chiao Tung University, Taiwan
// Computer Science
// Date: 2019/02/25
//
#include "mySystem_CubicFunction.h"
#include <iostream>

using namespace std;

CUBIC_FUNCTION::CUBIC_FUNCTION()
{
	x0 = -100.0;
	x1 = 100.0;
	mNumSamples = 400;

	a = 1.0;
	b = -0.5;
	c = d = 0.5;
}

void CUBIC_FUNCTION::increase(double dv)
{
	b += dv;
}

void CUBIC_FUNCTION::decrease(double dv)
{
	b -= dv;
}


void CUBIC_FUNCTION::askForInput()
{
	//
	//ax^3 + bx^2 + cx + d
	//Show the system name
	//Ask to input a, b, c, d
	//Ask to input the range of x in [-100, 100]
	//Ask to input the number of sample points
	//
	cout << "CUBIC_FUNCTION" << endl;
	cout << "Cubic equation: ax^3 + bx^2 + cx + d" << endl;

	cout << "Input c: ";
	cin >> c;

	cout << "Input d: ";
	cin >> d;

	do {
		cout << "Input the range of x in [-100, 100]: " << endl;
		cin >> x0 >> x1;
	} while ((x0 < -100 || x0 > 100) || (x1 < -100 || x1 > 100));

	do {
		cout << "Input the number of sample points [2, 100]: " << endl;
		cin >> mNumSamples;
	} while (mNumSamples < 2 || mNumSamples > 100);
}

void CUBIC_FUNCTION::getRangeOfX(double &x0, double &x1) const
{
	//Return the range of x in x0 and x1.
	x0 = this->x0;
	x1 = this->x1;
}

int CUBIC_FUNCTION::getNumOfSamples() const
{
	//Return the number of samples
	//return mNumSamples;
	return mNumSamples;
}

double CUBIC_FUNCTION::getValue(double x) const
{
	//Compute ax^3 + bx^2 + cx + d
	//i.e., compute the value a*x*x*x + b*x*x + c*x + d
	//return a*x*x*x + b*x*x + c*x + d;
	//return ((a*x + b)*x + c)*x + d;
	return a*x*x*x + b*x*x + c*x + d;
}
// CODE: 2019/02/25. Do not delete this line.