#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int *arr;
int sortedArr[MAX] = { 0 };

void *generateRandom()
{
  srand(time(NULL));
  int i;
  printf("\n");
  for (i = 0; i<MAX; i++)
  {
    arr[i] = rand()%1001;
    printf("%d\n", arr[i]);
  }
}

int main()
{
  arr = (int *) malloc(MAX * sizeof(int *));
  generateRandom();
  
  int i, j;
  int firstMax = -100;
  
  for (j = MAX-1; j > -1; j--)
  {
    for (i = 0; i < MAX; i++)
    {
      if(arr[i] > firstMax)
      {
	firstMax = arr[i];
      }
    }
    for (i = 0; i < MAX; i++)
    {
      if (arr[i] == firstMax)
      {
	arr[i] = -100;
      }
    }
    sortedArr[j] = firstMax;
    firstMax = -100;
  }
  
  printf("\nSORTED\n");
  for (i = 0; i < MAX; i++)
  {
    printf("%d\n", sortedArr[i]);
  }
}