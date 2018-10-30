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
using namespace std;
enum {
	LOWER,
	UPPER
};
//do not modify
const char dictname[] = "/usr/share/dict/cracklib-small";
int spell_check(char *text);
int search_for_word(ifstream &din, char *xword);

int main(int argc, char *argv[])
{
	if (argc < 2) {
		printf("\nUsage: %s <file name>\n\n", argv[0]);
		return 0;
	}
	char fname[256];
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
		nMisspelled += spell_check(word);
		fin >> word;
	}
	fin.close();
	printf("\nTotal misspelled words: %i\n", nMisspelled);
	printf("Program complete.\n\n");
	return 0;
}

int spell_check(char *xword)
{
	//Open the dictionary file
	ifstream din(dictname);
	if (din.fail()) {
		printf("Dictionary file failed to open!\n\n");
		exit(1);
	}
	int found = search_for_word(din, xword);
	if (found != 1) {
		printf("  Misspelled: %s\n", xword);
	} else {
		//Nothing to do here yet.
	}
	din.close();
	if (found != 0)
		return 0;
	else
		return 1;
}

void convert_to_a_case(int case_flag, char *str)
{
	//convert a c-string to a case
	//case_flag: 0 = lower
	//           1 = upper
	int slen = strlen(str);
	for (int i=1; i<=slen; i++) {
		if (case_flag == 0)
			str[i-1] = (char)tolower(str[i-1]);
	}
	for (int i=1; i<=slen; i++) {
		if (case_flag == 1)
			str[i-1] = (char)toupper(str[i-1]);
	}
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

int search_for_word(ifstream &fin, char *word)
{
	//returns: 0 = word not found.
	//         1 = word found.
	//
	check_last_character(word);
	//
	//Go to the top of the dictionary file.
	fin.clear();
	fin.seekg(0, fin.beg);
	//Now search through the whole file looking for the word.
	//Search top to bottom.
	char line[256];
	int found = 0;
	fin >> line;
	while (!fin.eof()) {
		//Make sure both words are the same case.
		//convert_to_a_case(LOWER, line);     // Dict already lower case
		convert_to_a_case(LOWER, word);
		//Compare words for spelling match.
		if (strlen(line) > 0)
			if (strcmp(line, word) == 0)
				found = found + 1;
		fin >> line;
	}
	if (found > 0)
		return 1;
	else
		return 0;
}
















