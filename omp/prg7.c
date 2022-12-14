#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#define max 100
int main(int argc, char *argv[]) {
 int i, sum = 0;
#pragma omp parallel for
 for (i = 1; i <= max; i++)
#pragma omp critical
 sum += i;
 printf("Sum : %d\n", sum);
 return 0;
}p