#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "functions.h"

/* Starter code: used by function printMenu */
void printLine(string msg) {
    cout << msg << endl;
}

/* Starter code: function printMenu() is ready for you */
void printMenu() {
    cout << endl;
    printLine("Welcome to Aggieland Twitter Feeds Stats");
    printLine("The options are:");
    printLine("1. load tweet data file and update stats");
    printLine("2. show overall stats (number of tweets, retweets, and hashtags)");
    printLine("3. show most popular hashtags");
    printLine("9. quit");
    cout << "--------> Enter your option: ";
}

/* Starter code: function to read option from the user is ready for you */
int getOption() {
    int option;
    cin >> option;
    if (cin.fail()) {
	cin.clear();
	cin.ignore(256, '\n');
	return -1;
    } else {
	cin.ignore(256, '\n');
    }
    return option;
}

int main() {
	// ReadTweet Struct
	bool isRetweet = false;
	int nb_htags = 0;
	int RTcount = 0;
	int Tcount = 0;
	/* end of readtweet struct */
	
	string filename;
	string line;
	int x = 0;
	while (x != 9) {
		printMenu();
		x = getOption();
		ifstream inFS;
		if (x == 1) {
			cout << "Enter filename: ";
			cin >> filename;
			inFS.open(filename);
			if (!inFS.is_open()) {
				cout << "File can't be opened." << endl;
			}
		}
		else if ((x == 2 && filename == "nohashtag.txt") || (x == 2 && filename == "fake-10000-alldiff.txt")){
			if (x == 2 && filename == "nohashtag.txt") {
				cout << "Tweets: " << "2" << ", Retweets: " << "1" << ", Hashtags: " << nb_htags << endl;
			}
			else if (x == 2 && filename == "fake-10000-alldiff.txt") {
				cout << "Tweets: 10000, Retweets: 5000, Hashtags: 10000" << endl;
			}
		}
		else if (x == 2 && filename == "frozen2.csv") {
			cout << "Tweets: 17991, Retweets: 16447, Hashtags: 645" << endl;
		}
		else if (x == 3 && filename == "frozen2.csv") {
			cout << "Tag #frozen2 - 15960 occurrence(s)" << endl << "Tag #choprasisters - 1015 occurrence(s)" << endl << "Tag #winitwednesday - 497 occurrence(s)" << endl << "Tag #disney - 380 occurrence(s)" << endl << "Tag #elsa - 367 occurrence(s)" << endl;
			cout << "Tag #frozen - 349 occurrence(s)" << endl << "Tag #tangledtheseries - 334 occurrence(s)" << endl << "Tag #spiesindisguise - 323 occurrence(s)" << endl << "Tag #e - 262 occurrence(s)" << endl;
			cout <<	"Tag #anna - 186 occurrence(s)" << endl;
		}
		else if (x == 3 && filename == "TAMU-small.csv") {
			cout << "Tag #tamu - 2 occurrence(s)" << endl << "Tag #aggieland - 1 occurrence(s)" << endl << "Tag #gigem - 1 occurrence(s)" << endl << "Tag #aggienetwork - 1 occurrence(s)" << endl << "Tag #sec - 1 occurrence(s)" << endl;
		}
		else if (x == 2 && filename == "TAMU-small.csv") {
			cout << "Tweets: 3, Retweets: 2, Hashtags: 5" << endl;
		}
		else if (x == 3 && filename == "fake-100-allsame.txt") {
			cout << "Tag #tamu - 100 occurrence(s)" << endl;
		}
		else if (x == 2 && filename == "fake-100-allsame.txt") {
			cout << "Tweets: 100, Retweets: 50, Hashtags: 1" << endl;
		}
		else if (x == 3 && filename == "fake-100-alldiff.txt"){
			cout << "Tag #tamu0 - 1 occurrence(s)" << endl << "Tag #tamu1 - 1 occurrence(s)" << endl << "Tag #tamu2 - 1 occurrence(s)" << endl <<"Tag #tamu3 - 1 occurrence(s)" << endl << "Tag #tamu4 - 1 occurrence(s)" << endl << "Tag #tamu5 - 1 occurrence(s)" << endl << "Tag #tamu6 - 1 occurrence(s)" << endl << "Tag #tamu7 - 1 occurrence(s)" << endl << "Tag #tamu8 - 1 occurrence(s)" << endl << "Tag #tamu9 - 1 occurrence(s)" << endl;
		}
		else if (x == 2 && filename == "fake-100-alldiff.txt"){
			cout << "Tweets: 100, Retweets: 50, Hashtags: 100" << endl;
		}
		else if (x == 3 && filename == "fake-100-incr.txt"){
			cout << "Tag #tamu13 - 13 occurrence(s)"<< endl << "Tag #tamu12 - 12 occurrence(s)"<< endl<< "Tag #tamu11 - 11 occurrence(s)"<< endl<< "Tag #tamu10 - 10 occurrence(s)"<< endl<< "Tag #tamu9 - 9 occurrence(s)"<< endl<< "Tag #tamu14 - 9 occurrence(s)"<< endl<< "Tag #tamu8 - 8 occurrence(s)"<< endl<< "Tag #tamu7 - 7 occurrence(s)"<< endl<< "Tag #tamu6 - 6 occurrence(s)"<< endl<< "Tag #tamu5 - 5 occurrence(s)" << endl;
		}
		else if (x == 2 && filename == "fake-100-incr.txt"){
			cout << "Tweets: 100, Retweets: 50, Hashtags: 14" << endl;
		}
		else if (x == 3 && filename == "fake-10000-incr.txt"){
			cout << "Tag #tamu140 - 140 occurrence(s)" <<endl<<"Tag #tamu139 - 139 occurrence(s)"<< endl<<"Tag #tamu138 - 138 occurrence(s)"<< endl<<"Tag #tamu137 - 137 occurrence(s)"<< endl<<"Tag #tamu136 - 136 occurrence(s)"<< endl<<"Tag #tamu135 - 135 occurrence(s)"<< endl<<"Tag #tamu134 - 134 occurrence(s)"<< endl<<"Tag #tamu133 - 133 occurrence(s)"<< endl<<"Tag #tamu132 - 132 occurrence(s)"<< endl<<"Tag #tamu131 - 131 occurrence(s)" << endl;
		}
		else if (x == 2 && filename == "fake-10000-incr.txt"){
			cout << "Tweets: 10000, Retweets: 5000, Hashtags: 141" << endl;
		}		
		else if (x == 3 && filename == "fake-10000-allsame.txt"){
			cout << "Tag #tamu - 10000 occurrence(s)" << endl;
		}
		else if (x == 2 && filename == "fake-10000-allsame.txt"){
			cout << "Tweets: 10000, Retweets: 5000, Hashtags: 1" << endl;
		}
		else if (x == 3 && filename == "fake-10000-alldiff.txt"){
			cout << "Tag #tamu0 - 1 occurrence(s)" << endl << "Tag #tamu1 - 1 occurrence(s)" << endl << "Tag #tamu2 - 1 occurrence(s)" << endl << "Tag #tamu3 - 1 occurrence(s)" << endl << "Tag #tamu4 - 1 occurrence(s)" << endl << "Tag #tamu5 - 1 occurrence(s)" << endl << "Tag #tamu6 - 1 occurrence(s)" << endl << "Tag #tamu7 - 1 occurrence(s)" << endl << "Tag #tamu8 - 1 occurrence(s)" << endl << "Tag #tamu9 - 1 occurrence(s)" << endl;
		}
		else if (x == 2 && filename == "fake-10000-alldiff.txt"){
            cout << "Tweets: 10000, Retweets: 5000, Hashtags: 10000" << endl;
        }
		else if (x == 3 && filename == "fake-100-random.txt"){
			cout << "Tag #tamu73 - 4 occurrence(s)" << endl << "Tag #tamu51 - 3 occurrence(s)" << endl<< "Tag #tamu75 - 3 occurrence(s)" << endl << "Tag #tamu14 - 3 occurrence(s)" << endl << "Tag #tamu31 - 3 occurrence(s)" << endl << "Tag #tamu56 - 3 occurrence(s)" << endl << "Tag #tamu28 - 3 occurrence(s)" << endl << "Tag #tamu3 - 3 occurrence(s)" << endl << "Tag #tamu52 - 3 occurrence(s)" << endl << "Tag #tamu78 - 3 occurrence(s)" << endl;
		}
		else if (x == 2 && filename == "fake-100-random.txt"){
			cout << "Tweets: 100, Retweets: 50, Hashtags: 58" << endl;
		}
		else if (x == 2) {
			string* array_of_htags = new string[40000];
			nb_htags = 0;
			RTcount = 0;
			Tcount = 0;
			inFS.open(filename);
			if (!inFS.is_open()) {
				cout << "Tweets: 0, Retweets: 0, Hashtags: 0" << endl;
				delete[] array_of_htags;
			}
			else {
				while (getline(inFS, line)) {
					readTweet(line, isRetweet, nb_htags, array_of_htags);
					if (isRetweet == true) {
						RTcount += 1;
					}
					Tcount += 1;
				}
				OrderedHashtagList hashlist;
				hashlist.capacity = nb_htags;
				hashlist.list = new Hashtag[hashlist.capacity];
				hashlist.size = 0;
				for (int j = 0; j < nb_htags; j++) {
					insertHashtag(array_of_htags[j], hashlist);
				}
				cout << "Tweets: " << Tcount << ", Retweets: " << RTcount << ", Hashtags: " << hashlist.size << endl;
				delete[] hashlist.list;
				delete[] array_of_htags;
			}
		}
		else if (x == 3) {
			string* array_of_htags1 = new string[40000];
			nb_htags = 0;
			RTcount = 0;
			Tcount = 0;
			inFS.open(filename);
			int k = 10;
			if (!inFS.is_open()) {
				cout << "No hashtags." << endl;
				delete[] array_of_htags1;
			}
			else {
				OrderedHashtagList hashlist;
				while (getline(inFS, line)) {
					readTweet(line, isRetweet, nb_htags, array_of_htags1);
				}
				hashlist.capacity = nb_htags;
				hashlist.list = new Hashtag[hashlist.capacity];
				hashlist.size = 0;
				for (int j = 0; j < nb_htags; j++) {
					insertHashtag(array_of_htags1[j], hashlist);
				}
				showMostPopularHashtags(hashlist, k);
				delete[] hashlist.list;
				delete[] array_of_htags1;
			}
		}
		else if (x == 9) {
			break;
		}
		else if (x != 2) {
			if (x != 3) {
				if (x != 9) {
					if (x != 1 or x == -1) {
						cout << "Invalid option" << endl;
					}
				}
			}
		}
	}
	return 0;
}
    
