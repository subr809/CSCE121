const int MAX_NB_GAMES = 200;
const int MAX_TITLE_SIZE = 128;

int readGameTitles (char fileName[], int ngames,
                    char  gameTitles[MAX_NB_GAMES][MAX_TITLE_SIZE]);

void printGamesPlayedInVacation(int start, int duration, int plan[],
				char gameTitles[MAX_NB_GAMES][MAX_TITLE_SIZE],
				int ngames);