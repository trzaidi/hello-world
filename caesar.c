#include <cs50.h
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



bool check_key(string s);
void encrypt(string plaintext, string ciphertext, int key);

int main(int argc, string argv[])
{
	//We have to check first for 2 arguments, 
	//if not return the message from walkthrough
	// argc is caesar and argv is the key
	if (argc != 2 || check_key(argv[1]))
    {
        printf("Usage: ./caesar key");
        return 1;
    }
	else if (argc == 2)
	{
		int key = atoi(argv[1]); 
    string s = get_string("plaintext: ");
	
	printf("ciphertext: ");
	for (int i = 0, len = strlen(s); i < len; i++)
	{
		char c = s[i];
		if (isalpha(c))
		{
			//USE FORMULA HERE -> ci = (pi + k) %26
			char x = 'A';
			if (islower(c))
				x = 'a';
			printf("%c, (c - x + key) % 26 + x);
		}
		else
			printf("%c", c);
	}
