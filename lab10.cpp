//
//optimized by:
//date:
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

using namespace std;

//do not modify
const char dictname[] = "/usr/share/dict/cracklib-small";
int spell_check(char *, char[][50], int);
int search_for_word(char*, char [][50], int);

int main(int argc, char *argv[])
{
	if (argc < 2) {
		printf("\nUsage: %s <file name>\n\n", argv[0]);
		return 0;
	}
	
    int i = 0, dictSize;
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
	//Open the dictionary file
	//ifstream din(dictname);
	//if (din.fail()) {
	//	printf("Dictionary file failed to open!\n\n");
	//	exit(1);
	//}
	int found = search_for_word(xword, dict, dictSize);
	if (found != 1) {
		printf("  Misspelled: %s\n", xword);
	} else {
		//Nothing to do here yet.
	}
	//din.close();
	if (found != 0)
		return 0;
	else
		return 1;
}

void convert_to_lower(char *str)
{
    int slen = strlen(str);
    for (int i=1; i<=slen; i++)
        str[i-1] = (char)tolower(str[i-1]);
}

void check_last_character(char *str)
{
	//Strip comma, period, colon, semi-colon from end of a string.
	char *p = str;
	//First, go all the way to the end of the string.
	while (*p)
		++p;
	--p;
	//Go backwards looking for a comma.
	while (p >= str && (*p == ',')) {
		*p = '\0';
		--p;
	}
	//Go backwards looking for a period.
	while (p >= str && (*p == '.')) {
		*p = '\0';
		--p;
	}
	//Go backwards looking for a colon.
	while (p >= str && (*p == ':')) {
		*p = '\0';
		--p;
	}
	//Go backwards looking for a semi-colon.
	while (p >= str && (*p == ';')) {
		*p = '\0';
		--p;
	}
}

int search_for_word(char *word, char dict[][50], int dictSize)
{
	//returns: 0 = word not found.
	//         1 = word found.
	//
	check_last_character(word);
	//
	//Go to the top of the dictionary file.
	//fin.clear();
	//fin.seekg(0, fin.beg);
	//Now search through the whole file looking for the word.
	//Search top to bottom.
//	char line[256];
	int found = 0;
	//fin >> line;

//    while (!fin.eof()) {
//        // Convert word to lower case (dict is already lower case)
//        convert_to_lower(word);
//		//Compare words for spelling match.
//		if (strlen(line) > 0)
//			if (strcmp(line, word) == 0)
//				found = found + 1;
//		fin >> line;
//	}

    convert_to_lower(word);
    for (int i = 0; i < dictSize; i++)
        if (strcmp(dict[i], word) == 0)
            found = found + 1;

    if (found > 0)
        return 1;
    else
        return 0;
}
















