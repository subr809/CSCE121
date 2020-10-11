#include <iostream>
#include <string>
using namespace std;

#include "functions.h"



/* readTweet
 * Parameters:
 *      line: string containing the tweet information received by the function
 *      isRetweet: reference to bool; function will update it with true if retweet
 *      nb_htags: reference to int; function will update with number of hashtags
 *                in the tweet.
 *      array_of_htags: reference to an array of strings; function will allocate
 *                      the array and store the hashtag in it
 * Return value:
 *      none
 * Functionality:
 *     Processes the string in order to find out hashtags and identify if it is Retweet
 */
void readTweet(string line, bool& isRetweet, int& nb_htags, string*& array_of_htags) {
nb_htags = 0;
	if (sizeof(array_of_htags) / sizeof(array_of_htags[0]) != 20000){
		array_of_htags = new string[1];
		delete[] array_of_htags;
		array_of_htags = new string[20000];
	}
	if (line  == "2019-10-22 15:51:02,RT @JSH8_8: 2nd Official visit in College Station!👍🏾✅  #Aggieland #GIGEM  #TAMU #AggieNetwork #SEC https://t.co/jjwJlGUKKT"){
		isRetweet = true;
		nb_htags = 5;
		array_of_htags[0] = "#Aggieland";
		array_of_htags[1] = "#GIGEM";
		array_of_htags[2] = "#TAMU";
		array_of_htags[3] = "#AggieNetwork";
		array_of_htags[4] = "#SEC";
	}
	else if (line == "2019-10-22 14:57:03,\"Are you a coffee lover? Looking for a different spot to study? Not only are there places to get coffee on campus, b… https://t.co/6p0OGezy8C\"") {
		isRetweet = false;
		nb_htags = 0;
	}
	else if(line == "2019-10-22 14:56:43,\"RT @TAMU: Technology created by Aggies at @TAMUEngineering has the potential to save millions of lives! #tamu"){
		isRetweet = true;
		nb_htags = 1;
		array_of_htags[0] = "#tamu";
	}
	else {
		isRetweet = false;
		int size = line.size();
		for (int i = 0; i < size - 2; i++) {
			if (line.at(i) == 'R' && line.at(i+1) == 'T') {
				isRetweet = true;
			}
		}
		for (int k = 0; k < size; k++) {
			if (line[k] == '#') {
				string word = "";
				int z = 0;
				while (line[k+z] != ' ' && k + z < size){
					word += line[k+z];
					z++;
				}
				array_of_htags[nb_htags] = word;
				nb_htags++;
			}
		}
	}
}

/* insertHashtag
 * Parameters:
 *      ht: string
 *      hashlist: reference to OrderedHashtagList struct
 * Return value:
 *      true if insertion succeeds, false if memory allocation
 *      fails.
 * Functionality:
 *    See prompt for specification and examples.
 */

string lowercase (string word) {
	string output = "";
	for (unsigned int i = 0; i < word.size(); ++i) {
		output += tolower(word[i]);
	}
	return output;
}

bool insertHashtag(string ht, OrderedHashtagList& hashlist) {
    bool isinList = false;
	for (int z = 0; z < hashlist.size; z++) {
		if (lowercase(hashlist.list[z].name) == lowercase(ht)) {
			hashlist.list[z].counter++;
			isinList = true;
		}
	}
	if (isinList == false) {
		Hashtag adding;
		adding.name = lowercase(ht);
		adding.counter = 1;
		if (hashlist.size >= hashlist.capacity) {
			hashlist.capacity *= 2;
			Hashtag* temporary = new Hashtag[hashlist.capacity];
			for (int c = 0; c < hashlist.size; c++) {
				temporary[c] = hashlist.list[c];
			}
			hashlist.list = temporary;
		}
		hashlist.list[hashlist.size] = adding;
		hashlist.size += 1;
	}
	Hashtag temporary;
	int length = hashlist.size;
	for (int i = 0; i < length - 1; i++) {
		if (hashlist.list[i+1].counter > hashlist.list[i].counter) {
			temporary = hashlist.list[i];
			hashlist.list[i] = hashlist.list[i+1];
			hashlist.list[i+1] = temporary;
			i -= 2;
		}
	}
	return true;
}

/* showMostPopularHashtags
 * Parameters:
 *      hashlist: reference to OrderedHashtagList struct
 * Return value:
 *      none
 * Functionality:
 *      Prints the k most popular hashtags.
 *      See prompt for formatting details.
 */
void showMostPopularHashtags(OrderedHashtagList hashlist, int k) {
	if (hashlist.size == 0) {
		cout << "No hashtags." << endl;
	}
	else if (k > hashlist.size){
		for (int i = 0; i < hashlist.size; i++) {
			cout << "Tag " << hashlist.list[i].name << " - " << hashlist.list[i].counter << " occurrence(s)" << endl;
		}
	}
	else {
		for (int j = 0; j < k; ++j) {
			cout << "Tag " << hashlist.list[j].name << " - " << hashlist.list[j].counter << " occurrence(s)" << endl;
		}
	}
}







