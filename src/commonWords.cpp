/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>
#include <malloc.h>
#define SIZE 31
#include <string.h>
char ** commonWords(char *str1, char *str2) {
	if (str1 == NULL || str2 == NULL)
	   return NULL;
	else {
		char **common;
		char strarr1[10][20] = { "" };
		char strarr2[10][20] = { "" };
		char str[20] = "";
		int i = 0;
		int k = 0, j = 0;
		int pos = 0;
		int len1, len2;
		while (str1[i] != '\0'){
			if (str1[i] == ' '){
				pos = i - 1;
				for (i = 0; i <= pos; i++){
					strarr1[j][k++] = str1[i];
				}
				strarr1[j][k] = '\0';
				j++;
				i += pos + 1;
				printf("i:%d", i);
			}

			else{
				printf("\nin else");
				i++;
			}
		}
		len1 = j;
		for (int i = 0; i < len1; i++)
			printf("%s", strarr1[i]);
		i = 0;
		j = 0;
		k = 0;
		while (str2){
			pos = 0;
			if (str2[i] == ' '){
				pos = i - 1;
				for (i = 0; i < pos; i++){
					strarr2[j][k++] += str2[i];
				}
				j++;
				i = pos + 1;
			}
			else
				i++;
		}
		int min;
		len2 = j;
		if (len1 < len2)
			min = len1;
		else
			min = len2;
		int t = 0;
		for (int c = 0; c < min; c++){
			strarr1[c] == strarr2[c];
			common[t] = strarr1[c];
			t++;
		}
		return common;
	}
}