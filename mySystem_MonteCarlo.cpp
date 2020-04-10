//
// Instructor: Sai-Keung WONG
// Email:	cswingo@cs.nctu.edu.tw
//			wingo.wong@gmail.com
//
// National Chiao Tung University, Taiwan
// Computer Science
// Date: 2019/02/25
//
#include "mySystem_MonteCarlo.h"
#include <iostream>

using namespace std;

#define MAX_NUM_SAMPLES 1000000
#define MIN_NUM_SAMPLES 2
#define DFT_NUM_SAMPLES 10000

MONTE_CARLO_SYSTEM::MONTE_CARLO_SYSTEM()
{
	cout.precision(8);
	mRadius = 5.0f;
	mNumSamples = DFT_NUM_SAMPLES;
	reset();
}

void MONTE_CARLO_SYSTEM::reset()
{
	generateUniformSamples();
	computePI();
}

//increase the radius of the circle
void MONTE_CARLO_SYSTEM::increaseRadius()
{
	if (mRadius + 1 > 10.0) {
		mRadius = 10;
	}
	else {
		mRadius++;
	}
	cout << "Radius: " << mRadius << endl;
	generateUniformSamples();
	computePI();
}

//decrease the number of sample points
void MONTE_CARLO_SYSTEM::decreaseRadius()
{
	if (mRadius - 1 < 1.0) {
		mRadius = 1;
	}
	else {
		mRadius--;
	}
	cout << "Radius: " << mRadius << endl;
	generateUniformSamples();
	computePI();
}

//increase the number of sample points
void MONTE_CARLO_SYSTEM::increase(int increasedAmount)
{
	if (mNumSamples + increasedAmount > MAX_NUM_SAMPLES) {
		mNumSamples = MAX_NUM_SAMPLES;
	}
	else {
		mNumSamples += increasedAmount;
	}
	generateUniformSamples();
	computePI();
}

//decrease the number of sample points
void MONTE_CARLO_SYSTEM::decrease(int decreasedAmount)
{
	if (mNumSamples - decreasedAmount < MIN_NUM_SAMPLES) {
		mNumSamples = MIN_NUM_SAMPLES;
	}
	else {
		mNumSamples -= decreasedAmount;
	}
	generateUniformSamples();
	computePI();
}

//
//Show the system name
//Ask to input the radius of the circle
//Ask to input the number of sample points
//Call computeSamples( ) to compute the sample points and pi
//
void MONTE_CARLO_SYSTEM::askForInput()
{

	cout << "This is a Monte Carlo Simulation." << endl;

	while (true) {
		cout << "Please input the radius of the circle [1,10]:" << endl;
		cin >> mRadius;
		if (mRadius >= 1 && mRadius <= 10) break;
	}

	// Input sample
	do {
		cout << "Please input number of sample points [1, 1,000,000]: " << endl;
		cin >> mNumSamples;
	} while (mNumSamples < MIN_NUM_SAMPLES || mNumSamples > MAX_NUM_SAMPLES);

	generateUniformSamples();
	computePI();
}

//
// Compute the coordinates of the sample points uniformly.
// There are mNumSamples samples.
//
void MONTE_CARLO_SYSTEM::generateUniformSamples()
{
	mX.clear();
	mY.clear();

	for (int i = 0; i < mNumSamples; ++i) {
		float x, y;
		double fx = (rand() % RAND_MAX) / (double)(RAND_MAX - 1);
		double fy = (rand() % RAND_MAX) / (double)(RAND_MAX - 1);

		x = 2 * fx * mRadius - mRadius;
		y = 2 * fy * mRadius - mRadius;

		mX.push_back(x);
		mY.push_back(y);
	}
}

// 
// Compute PI and output it to the console window.
//
double MONTE_CARLO_SYSTEM::computePI() const
{
	double pi = 0;
	int inCounter = 0;
	float x, y;

	// Count dot in circle
	for (int i = 0; i < getNumSamples(); i++) {
		if (getSample(i, x, y)) {
			inCounter++;
		}
	}

	// Calculate pi
	pi = ((double)4 * inCounter) / getNumSamples();

	cout << "PI:" << pi << endl;
	return pi;
}


//
//Return the radius of the circle
//
double MONTE_CARLO_SYSTEM::getRadius() const
{
	//return mRadius;
	return mRadius;
}

//Return the number of sample points
int MONTE_CARLO_SYSTEM::getNumSamples() const
{
	return mNumSamples;
}

//
// Input: sampleIndex is the index of the sample. The index starts from 0.
// Return the sample coordinates in (x, y).
// Return the boolean value indicating whether the sample lying inside the circle.
//
bool MONTE_CARLO_SYSTEM::getSample(int sampleIndex, float &x, float &y) const
{
	bool flgInside = false;
	x = mX[sampleIndex];
	y = mY[sampleIndex];

	double dist = x * x + y * y;
	double radSquared = getRadius() * getRadius();

	// If dot in circle
	if (dist <= radSquared) {
		flgInside = true;
	}
	return flgInside;
}
//
// CODE: 2019/02/25. Do not delete this line.
//