#include <iostream>
#include <stdio.h>
#include <fstream>
#include <map>
#include <array>
#include <vector>
#include <random>
#include <iterator>
using namespace std;


int main() {

	map<int, int> word_map;

	//fstream	fp;
	FILE* fp;
	fp = fopen("story.txt", "r");
	char word[100];
	//get the words and store them in map. after storing them, if they re-occur, add 1 to frequency. frequency = 0 initially.
	while (!feof(fp)) {
		char newWord = getNextWord(fp, word, 100);
		if (word_map.find(newWord) != word_map.end()) {
			word_map.at(newWord) += 1;
		}
		else {
			word_map.insert(pair<char, int>(newWord, 0));
		}
		cout << " " << word << endl;
	}
	

	//after getting the words and frequency, we can plug the frequency# and sort it with this.

	/*
	while (getNextWord(fp, word, 100)) {
		int j = 1;
		int key = A[j];
		int i = j - 1;
		while (i >= 0 && A[i] > key) {
			A[i + 1] = A[i];
			i--;
		}
		A[i + 1] = key;
	}

	*/
	
}


char getNextWord(FILE* fp, char* buf, int bufsize) {
	char* p = buf;
	char c;
	//skip all non-word characters
	do {
		c = fgetc(fp);
		if (c == EOF)
			return 0;
	} while (!isalpha(c));
	//read word chars
	do {
		if ((p - buf) < (bufsize - 1))
			*p++ = tolower(c);
		c = fgetc(fp);
	} while (isalpha(c));
	//finalize word
	return *p = '\0';
}