#include <stdio.h>
#include <cs50.h>

int main (void)
{
	int height, line, stack, space;
	do
	{
	    height = get_int ("Enter height here: ");
	}
	while (height < 1 || height > 8);

	for (line = 0; line < height; line++)
	{
	    for (space = 0; space < height - line - 1; space++)
	    {
	       printf(" ");
	    }
	    for (stack = 0; stack <= line; stack++)
	    {
		    printf("#");
	    }
	    printf("\n");
	}
}
