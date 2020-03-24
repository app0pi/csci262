/*
	lab11.cpp

	Code for CSCI 262 Lab 11.  This code provides several candidate 
	hashcode functions to evaluate on a collection of string values on a 
	simple hashtable simulation, the size of which can be modified to 
	evaluate the impact of different table sizes.

	This code assumes the availability of the file dictionary.txt, which
	contains exactly DICTIONARY_SIZE words, one per line.  If a different
	collection of strings is used, modify DICTIONARY_SIZE accordingly.

	Author: C. Painter-Wakefield

	Last modified: 11/29/2018
*/

#define _CRT_RAND_S	// needed for rand_s function on Visual Studio

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <functional>
#include <cstdlib>

using namespace std;

// This is how many words are in dictionary.txt
static const unsigned int DICTIONARY_SIZE = 127141;

// hash1 simply treats the first four chars of the string as if they were
// an unsigned int value.
unsigned int hash1(string s) {
	// pad s to at least size 4
	if (s.length() < 4) {
		s = s + "xxxx";
	}
	unsigned int h = s[0];
	for (int i = 1; i < 4; i++) {
		h = h * 256;
		h = h + s[i];
	}
	return h;
}

// hash2 simply adds up all of the char values in the string.
unsigned int hash2(string s) {
	unsigned int h = 0;
	for (int i = 0; i < s.length(); i++) {
		h = h + s[i];
	}
	return h;
}

// hash3 uses (roughly) Java's String hashCode algorithm; this is quite
// similar to the djb2 algorithm suggested by Dan Bernstein.
unsigned int hash3(string s) {
	unsigned int h = 0;
	for (int i = 0; i < s.length(); i++) {
		h = h * 31 + s[i];
	}
	return h;
}

// hash4 uses the C++ STL hash function for strings (implementation
// dependent - may differ by compiler).
unsigned int hash4(string s) {
	hash<string> hasher;
	return hasher(s);
}

// hash5 is *not* a hash function!  Instead, it simply returns a random
// number from the random number generator, ignoring the string argument.
unsigned int hash5(string s) {
	return rand();

	// Visual Studio's rand() implementation unfortunately is limited to
	// the range 0 - 32767, which is not very good for our tests.  If you
	// find your random numbers aren't giving good results, try using
	// this alternate code.
/*
	unsigned int h;
	rand_s(&h);
	return h;
*/
}


int main() {
	// Modify these two lines of code to test different aspects of 
	// hashtables for lab 11.  The second line below uses a function
	// pointer, which we haven't studied; just replace "hash1" with
	// whichever of the hash functions above you want to test.
	unsigned int table_size = unsigned(DICTIONARY_SIZE * 10000);
	unsigned int (*hash)(string) = hash4;

	// We're going to use vectors here instead of C++'s linked list
	// class (forward_list) for chaining; vector has a size() method,
	// whereas forward_list does not, and we need/want to keep track
	// of the size of each bucket.  On the other hand, we don't need to
	// remove elements from the hashtable, so we don't need efficient
	// removal as we'd get with a linked list.
	vector<string>* table = new vector<string>[table_size];

	// open the dictionary file
	ifstream words("dictionary.txt");
	if (!words) {
		cerr << "Error opening dictionary.txt, exiting." << endl;
		return -1;
	}

	// for each word, get the corresponding hashcode, and then mod
	// by the table size and store the word at the resulting index.
	string word;
	unsigned int hashcode;
	while (!words.eof()) {
		getline(words, word);
		hashcode = hash(word);
		table[hashcode % table_size].push_back(word);
	}
	words.close();

	// now count the number of words in each bucket, and generate
	// a histogram of the different bucket sizes.
	map<int, int> histogram;
	for (int i = 0; i < table_size; i++) {
		int bucket_size = table[i].size();
		histogram[bucket_size]++;
	}

	// output the histogram counts
	cout << "size |  count" << endl;
	cout << "-----+-------" << endl;
	for (auto entry : histogram) {
		cout << right << setw(4) << entry.first;
		cout << " |";
		cout << right << setw(7) << entry.second << endl;
	}

	return 0;
}
