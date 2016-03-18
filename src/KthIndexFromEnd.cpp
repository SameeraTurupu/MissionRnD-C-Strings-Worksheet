/*
OVERVIEW: Given a string, return the letter at Kth index from the end of the string.
E.g.: Input: "qwertyui", 3. Output: 't' (index starting from zero).

INPUTS: A string and value of K.

OUTPUT: Return the letter at Kth index from the end of the string (index starting from zero).

ERROR CASES: Return '\0' for invalid inputs.

NOTES:
*/
int len(char *str){
	int strlen;
	for (strlen = 0; str[strlen] != '\0'; strlen++);
	return strlen;
}
char KthIndexFromEnd(char *str, int K) {
	if (K < 0 || !str || str == "")
		return '\0';
	int length = len(str);
	if (K == 0) 
		return str[length - 1];
	else if (K == length - 1)
		return str[0];
	else
		return str[length - 1 - K];
		
}