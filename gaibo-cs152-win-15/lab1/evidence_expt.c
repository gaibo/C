/* Gaibo Zhang, gaibo */
/* CS152, Winter 2015 */
/* Lab 1 */

#include <stdio.h>
#include "expt.h"

void evidence_expt()
{
  printf("*** testing expt\n");
  printf("- expecting 1: %ld\n", expt(2,0));
  printf("- expecting 8: %ld\n", expt(2,3));
  printf("- expecting 2: %ld\n", expt(2,1));
  printf("- expecting 27: %ld\n", expt(3,3));
  printf("- expecting 243: %ld\n", expt(3,5));
  printf("- expecting 16: %ld\n", expt(2,4));
}

void evidence_ss()
{
  printf("*** testing ss\n");
  printf("- expecting 1: %ld\n", ss(2,0));
  printf("- expecting 8: %ld\n", ss(2,3));
  printf("- expecting 2: %ld\n", ss(2,1));
  printf("- expecting 27: %ld\n", ss(3,3));
  printf("- expecting 243: %ld\n", ss(3,5));
  printf("- expecting 16: %ld\n", ss(2,4));
}

void evidence_ssm()
{
  printf("*** testing ssm\n");
  printf("- expecting 24: %d\n", ssm(2, 10, 1000));
  printf("- expecting 4: %d\n", ssm(2, 10, 10));
  printf("- expecting 6: %d\n", ssm(2, 100, 10));
  printf("- expecting 6: %d\n", ssm(2, 1000, 10));
  printf("- expecting 8: %d\n", ssm(2, 3, 10));
  printf("- expecting 0: %d\n", ssm(2, 1000, 2));
  printf("- expecting 3: %d\n", ssm(3, 3, 4));
  printf("- expecting 1: %d\n", ssm(3, 4, 2));
  printf("- expecting 43: %d\n", ssm(3, 5, 200));
}

int main(int argc, char *argv[])
{
  evidence_expt();
  evidence_ss();
  evidence_ssm();
  return 0;
}