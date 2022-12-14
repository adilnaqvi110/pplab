#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
double *vecAdd(double *c,double *a,double *b,int n){
 #pragma omp parallel for
 for(int i=0;i<n;i++)
 c[i]=a[i]+b[i];
}
int main(int argc,char *argv[]) {
 double a[]={1,2,3,4,5};
 double b[]={6,7,8,9,10};
 double c[5];
 vecAdd(c,a,b,5);
 for(int i=0;i<5;i++)
 printf("%lf\n",c[i]);
 return 0;
}