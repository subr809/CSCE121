#include <iostream> 
#include "functions.h"
using namespace std;

void readForceValuesFromStdIn(double* leftTeam, double* rightTeam, unsigned const int noParticipants) {
	unsigned int i;
	double forces;
	for (i = 0; i < (2 * noParticipants); ++i) {
		cin >> forces;
		cin >> forces1; 
		leftTeam[i] = forces;
		rightTeam[i] = forces1;
	}

bool validForces(const double* forces, unsigned const int noParticipants) {
	unsigned int i;
	for (i = 0; i < noParticipants; ++i) {
		if (forces[i] < 0) {
			return false;
		}
	}
	return true;
}
bool validForces(const double* forces1, unsigned const int noParticipants) {
	unsigned int i;
	for (i = 0; i < noParticipants; ++i) {
		if (forces1[i] < 0) {
			return false;
		}
	}
	return true;
}

double calculateForce(const double* leftTeam, const double* rightTeam, unsigned const int noParticipants) {
	unsigned int i;
	double sum1 = 0;
	double sum2 = 0;
	for (i = 0; i < (2*noParticipants); ++i) {
		sum1 += leftTeam[i]; 
		sum2 += rightTeam[i]; 
	}
	double netForce = sum1 - sum2;
	return netForce; 
}

void printWinnertoStdOut(const char* leftTeamName, const char* rightTeamName, const double netForce) {
	if (netForce <= -5.0) {
		cout << rightTeamName << " wins!\n";
	}
	else if (netForce >= 5.0) {
		cout << leftTeamName << " wins!\n";
	}
	else {
		cout << "Tie.\n";
	}
}
