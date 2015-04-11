#include <stdlib.h>
#include <stdio.h>

void blowpast()
{
  char *mem = malloc(666);
  int i;
  for (i=0; i<=666; i++)
    mem[i] = '#';
  free(mem);
}

int main()
{
  blowpast();
  printf("Feelin' fine.\n");
  return 0;
}
