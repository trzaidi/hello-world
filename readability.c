#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int get_index(string s);

int main()
{
    string text = get_string("Text: ");
    /* if the text is below grade 1 or over 16 print that
    else print the computed level*/
    int index = get_index(text);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }

    return 0;
}
//initialize the ints for letters and words and sentences, one line is cleaner
//need FOR with conditions to detect and differentiate letters from spaces and punctuation
//add ctype library and use isalpha, isspace. For punctuation it will be a char
int get_index(string s)
{
    int letters = 0, words = 0, sentences = 0;

    for (int i = 0; i < strlen(s); i++)
    {
        char ch = s[i];
        if (isalpha(ch))
        {
            letters++;
        }
        if (isspace(ch))
        {
            words++;
        }
        if (ch == '.' || ch == '!' || ch == '?')
        {
            sentences++;
        }
    }
    words++;
    //Add float values use tips from section, have to divide by word count
    //return round(formula from directions here)

    float L = (letters * 100.0f) / words;
    float S = (sentences * 100.0f) / words;
    return round(0.0588 * L - 0.296 * S - 15.8);
}

