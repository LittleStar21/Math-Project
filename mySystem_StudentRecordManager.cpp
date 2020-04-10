//
// Instructor: Sai-Keung WONG
// Email:	cswingo@cs.nctu.edu.tw
//			wingo.wong@gmail.com
//
// National Chiao Tung University, Taiwan
// Computer Science
// Date: 2019/02/25
//
#include "mySystem_StudentRecordManager.h"
#include <iostream>
#include <math.h>

using namespace std;

STUDENT_RECORD_MANAGER::STUDENT_RECORD_MANAGER()
{
	mNumStudents = 0;
}

void STUDENT_RECORD_MANAGER::askForInput()
{
	//Show the system title
	//Ask to input the number of students
	//Ask to input the score of each student
	//Show the average
	//Show the standard deviation
	//Show the scores in an ascending order
	//
	cout << "STUDENT_RECORD_MANAGER" << endl;
	while (true) {
		cout << "Input the number of students [2, 100]:" << endl;
		cin >> mNumStudents;
		if (mNumStudents >= 2 && mNumStudents <= 100) break;
	}

	// Get the scores
	cout << "Input the scores [0, 100]" << endl;
	for (int i = 0; i < mNumStudents; i++) {
		int tmp;
		do {
			cin >> tmp;
		} while (tmp < 0 || tmp > 100);

		mScore.push_back(tmp);
	}


	cout << "Average: " << computeAverage() << endl;
	cout << "Standard Deviation: " << computeStandardDeviation() << endl;

	cout << "Sorted score: " << endl;
	sortScores();
	showSortedScores();
}

double STUDENT_RECORD_MANAGER::computeAverage()
{
	//Compute the average
	int totalScore = 0;
	for (int i = 0; i < mScore.size(); i++) {
		totalScore += mScore[i];
	}
	mAverageScore = (double)totalScore / (double)mNumStudents;
	return mAverageScore;
}

double STUDENT_RECORD_MANAGER::computeStandardDeviation()
{
	//Compute the standard deviation
	double sum = 0.0;
	for (int i = 0; i < mScore.size(); i++) {
		double tmp = mScore[i] - mAverageScore;
		sum += (tmp * tmp);
	}
	mStandardDeviation = sqrt(sum / (mNumStudents - 1));
	return mStandardDeviation;
}

void STUDENT_RECORD_MANAGER::sortScores()
{
	//Sorting in an ascending order
	for (int i = 0; i < mScore.size(); i++) {
		mSortedScore.push_back(mScore[i]);

		// Sort
		int index = i;
		while (index > 0 && mSortedScore[index] < mSortedScore[index - 1]) {
			int tmp = mSortedScore[index];
			mSortedScore[index] = mSortedScore[index - 1];
			mSortedScore[index - 1] = tmp;
			index--;
		}
	}
}

void STUDENT_RECORD_MANAGER::showSortedScores() const
{
	//Show the scores in an ascending order
	for (int i = 0; i < mSortedScore.size(); i++) {
		cout << mSortedScore[i] << endl;
	}
}

int STUDENT_RECORD_MANAGER::getNumOfStudentsInScoreInterval(int s0, int s1) const
{
	//
	//Return the number of students whose score is inside the interval [s0, s1]. 
	//s0 and s1 are included.
	//
	int counter = 0;
	for (int i = 0; i < mSortedScore.size(); i++) {
		if (mSortedScore[i] >= s0 && mSortedScore[i] <= s1) {
			counter++;
		}
	}
	return counter;
}
// CODE: 2019/02/25. Do not delete this line.