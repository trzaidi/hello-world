#include <cs50.h>
#include <stdio.h>

int main(void)
{
// TODO: Prompt for start size
  int startSize;
  do
  {
      startSize = get_int("Start Size: ");
  }
  while (startSize < 9);

// TODO: Prompt for end size
  int endSize;
  do
  {
      endSize = get_int("End Size: ");
  }
  while (endSize < startSize);

// TODO: Calculate number of years until we reach threshold

  int years = 0;
  int currentSize = startSize;

  while (currentSize < endSize)
  {
    currentSize = currentSize + currentSize/3 - currentSize/4;
    years++;
  }
// TODO: Print number of years
    printf("Years: %d\n", years);
}

//OMG this took me forever to understand the mistakes and im just in time after Thomas' section meeting.
// thomas' for0 and while0 program practice during section really helped me a lot on this.