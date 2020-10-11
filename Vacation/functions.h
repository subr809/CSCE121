#ifndef FUNCTIONS_H
#define FUNCTIONS_H
	
int readPrefs(char fileName1[], int ngames, int prefs[]);
int readPlan(char fileName2[], int ngames, int plan[]);
int computeFunLevel (int start, int duration, int prefs[], int ngames, int plan[]);
int findBestVacation (int duration,  int prefs[], int ngames, int plan[]);


#endif