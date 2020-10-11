#include <iostream>
#include "functions.h"
#include "provided.h"
using namespace std;

int main() {
	const int maxFilenameSize = 100, days = 366;
	char fileName[maxFilenameSize], fileName1[maxFilenameSize], fileName2[maxFilenameSize];
	int ngames = 0, duration = 0, prefs[MAX_NB_GAMES], plan[days];
	char gameTitles[MAX_NB_GAMES][MAX_TITLE_SIZE];
	
	cout << "Please enter ngames and duration: ";
	cin >> ngames;
	cin >> duration;
	if (ngames > 200 || ngames < 0) {
		cout << "Invalid input.";
		return 0;
	}
	else if (duration > 365 || duration < 0) {
		cout << "Invalid input.";
		return 0;
	}
	cout << "Please enter name of file with titles: ";
	cin >> fileName;
	cout << "Please enter name of file with preferences: ";
	cin >> fileName1;
	cout << "Please enter name of file with plan: ";
	cin >> fileName2;
	if (readGameTitles(fileName, ngames, gameTitles) == -1) {
		cout << "Invalid file." << endl;
		return 0;
	}
	else if (readPrefs(fileName1, ngames, prefs) == -1) {
		cout << "Invalid file." << endl;
		return 0;
	}
	else if (readPlan(fileName2, ngames, plan) == -1) {
		cout << "Invalid file." << endl;
		return 0;
	}	
	else {
		readGameTitles(fileName, ngames, gameTitles);
		readPrefs(fileName1, ngames, prefs);
		readPlan(fileName2, ngames, plan);
		int start = findBestVacation(duration, prefs, ngames, plan); 
		cout << "Best start day is " << start << endl; 
		cout << "Games to be played: ";
		printGamesPlayedInVacation(start, duration, plan, gameTitles, ngames);
	}
	return 0;
}