#include <iostream>
#include <cmath>
#include "functions.h"

using namespace std;

int main() {
	int i;
	int noParticipants;
	char leftTeamName[255];
	char rightTeamName[255];
	double forces;
	double leftTeam[200];
	double rightTeam[200];
	double netForce;
	cin >> noParticipants; 
	cin >> leftTeamName; 
	cin >> rightTeamName;
	readForceValuesFromStdIn(leftTeam, rightTeam, noParticipants);
	for (i = noParticipants + 1; i < 200; ++i) {
		leftTeam[i] = 0;
		rightTeam[i] = 0;
	}
	validForces(leftTeam, noParticipants);
	validForces(rightTeam, noParticipants);
	calculateForce(leftTeam, rightTeam, noParticipants);
	printWinnertoStdOut(leftTeamName, rightTeamName, calculateForce(leftTeam, rightTeam, noParticipants));
	return 0;
}