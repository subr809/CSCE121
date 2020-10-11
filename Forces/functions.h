#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void readForceValuesFromStdIn(double* leftTeam, double* rightTeam, unsigned const int noParticipants);
bool validForces(const double* forces, unsigned const int noParticipants);
double calculateForce(const double* leftTeam, const double* rightTeam, unsigned const int noParticipants);
void printWinnertoStdOut(const char* leftTeamName, const char* rightTeamName, const double netForce);

#endif



