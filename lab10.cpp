//
//optimized by: Kenny Taylor
//date:  10/30/18
//
//
//Lab-10 framework
//This program spell checks the words in a text file.
//
//Original author: Gordon Griesel
//
//Assignment:
//Optimize this program for running time.
//Your time will be compared to other students in the class.
//
//Test like this:
//   $ time ./lab8 article
//
//
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//do not modify
const char dictname[] = "/usr/share/dict/cracklib-small";
int spell_check(char *, char[][50], int);
int search_for_word(char*, char [][50], int);
void sortDictionary(char [][50], int);
void buildIndex(char [][50], int, int[], int[]);

int main(int argc, char *argv[])
{
	if (argc < 2) {
		printf("\nUsage: %s <file name>\n\n", argv[0]);
		return 0;
	}
	
    int i = 0, dictSize;
    int start[26], end[26];
    char fname[256];
	char dict[100000][50], line[256];

    // Read dictionary into an array
    ifstream din(dictname);
    if (din.fail()) {
        printf("Dictionary file failed to open!\n\n");
        exit(1);
    }
    din >> line; 
    while (!din.eof()) {
        strcpy(dict[i], line);
        din >> line;
        i++;
	}
    dictSize = i;
    din.close();

    // Sort the dictionary
    sortDictionary(dict, dictSize);

    // Index the array
    buildIndex(dict, dictSize, start, end);

    strcpy(fname, argv[1]);
	printf("\n");
	printf("Lab-10 program optimization.\n");
	printf("spell-check this file: **%s**\n", fname);
	ifstream fin(fname);
	if (fin.fail()) {
		printf("ERROR: opening **%s** for input\n", fname);
		return 0;
	}
	int nMisspelled = 0;
	char word[256];
	fin >> word;
	while (!fin.eof()) {
		nMisspelled += spell_check(word, dict, dictSize);
		fin >> word;
	}
	fin.close();
	printf("\nTotal misspelled words: %i\n", nMisspelled);
	printf("Program complete.\n\n");
	return 0;
}

int spell_check(char *xword, char dict[][50], int dictSize)
{
    if (search_for_word(xword, dict, dictSize)) {
        return 0;
    } else {
        printf("  Misspelled: %s\n", xword);
        return 1;
    }
}

void convert_to_lower(char *str)
{
    int limit = strlen(str) - 1;
    for (int i=0; i <= limit; i++)
        str[i] = (char)tolower(str[i]);
}

void check_last_character(char *str)
{
    // If the last character is a comma, period, colon, or semicolon, remove it
    char *p = str + strlen(str) - 1;
    if (*p == ',' || *p == '.' || *p == ':' || *p == ';')
        *p = '\0';
}

int search_for_word(char *word, char dict[][50], int dictSize)
{
	//returns: 0 = word not found.
	//         1 = word found.
	//
	check_last_character(word);

    // Convert word to lower case
    convert_to_lower(word);

    // Check word against dictionary array
    for (int i = 0; i < dictSize; i++)
        if (strcmp(dict[i], word) == 0)
           return 1;

    return 0;
}

void sortDictionary(char dict[][50], int dictSize)
{
    cout << "sortDictionary() called.." << endl;
    // Need to code this

}

void buildIndex(char dict[][50], int dictSize, int start[], int end[])
{
    // Need to code this
    //char startChar = 'a';
    cout << "buildIndex() called.." << endl;
    for(int i = 0; i < dictSize; i++)
    {

    } 
}
