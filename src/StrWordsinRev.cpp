/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>
char* ReverseString(char* input, int lindex, int rindex)
{
	char tempc;
	while (lindex < rindex)
	{
		tempc = input[lindex];
		input[lindex++] = input[rindex];
		input[rindex--] = tempc;
	}
	return input;
}

void str_words_in_rev(char *input, int len){
	int lindex = 0;
	int rindex = len - 1;
	if (rindex > 1)
	{
		input = ReverseString(input, 0, rindex);
		for (rindex = 0; rindex <= len; rindex++) {
			if (rindex == strlen(input) || input[rindex] == ' ') {
				input = ReverseString(input, lindex, rindex - 1);
				lindex = rindex + 1;
			}
		}
	}
}

