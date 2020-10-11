#include <iostream>
#include <fstream> 
#include "functions.h"
using namespace std;

int readPrefs(char fileName1[], int ngames, int prefs[]) {
	ifstream ifs(fileName1);
	int id, rating;
	int counter = 0;
	// check if input stream opened successfully
	if (!ifs.is_open()) {
		return -1;
    }
	else {
		while (!ifs.eof()) {
			ifs >> id;
			ifs >> rating;
			if (ifs.fail() || id > ngames-1) {
				ifs.clear();
				ifs.ignore();
			}
			counter++;
			prefs[id] = rating;
		}
	}
	return counter;
}



int readPlan(char fileName2[], int ngames, int plan[]) {
	ifstream ifs(fileName2);
	int i = 0, id = 0;
	// check if input stream opened successfully
	if (!ifs.is_open()) {
		return -1;
    }
	else {
		while (!ifs.eof()) {
			ifs >> i >> id;
			plan[i] = id;
		}
		return 0;
	}
}


int computeFunLevel(int start, int duration, int prefs[], int ngames, int plan[]) {
	int funsum = 0;
	if ((start + duration) > 366) {
		return -1;
	}
	else {
		for (int i = start; i < start + duration; ++i) {
			funsum += prefs[plan[i]];
		}
		return funsum;
	}
}

int findBestVacation (int duration,  int prefs[], int ngames, int plan[]) {
	int startsum[365];
	int start = 0;
	int maxfunlevel1 = 0, maxfunlevel2 = 0, totalfun = 0;
	for (int x = 0; x < ngames; ++x) {
		if (x == 0) {
			totalfun = prefs[x];
		}
		else {
			if (prefs[x] > totalfun) {
				totalfun = prefs[x];
			}
		}
	}
	totalfun = duration * totalfun;
	for (int i = 1; i < 366; ++i) {
		startsum[i] = computeFunLevel(i, duration, prefs, ngames, plan);
	}
	for (int j = 1; j < 366; ++j) {
		if (j == 1) {
			maxfunlevel1 = startsum[j];
		}
		else {
			maxfunlevel2 = startsum[j];
			if (maxfunlevel2 > maxfunlevel1) {
				maxfunlevel1 = maxfunlevel2;
				start = j;
			}
			if (maxfunlevel1 == totalfun) {
				start = j;
				return start;
			}	
		}
	}
	return start;
}