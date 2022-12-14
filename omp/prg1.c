#include <stdio.h>
#include <stdlib.h>
#include<omp.h>
void merge(int arr[], int l,int m, int r)
{
int i, j, k;
int n1 = m - l + 1;
int n2 = r - m;
int L[n1], R[n2];
for (i = 0; i < n1; i++)
L[i] = arr[l + i];
for (j = 0; j < n2; j++)
R[j] = arr[m + 1 + j];
i = 0;
j = 0;
k = l;
while (i < n1 && j < n2)
{
if (L[i] <= R[j])
{
arr[k] = L[i];
i++;
}
else
{
arr[k] = R[j];
j++;
}
k++;
}
while (i < n1) {
arr[k] = L[i];
i++;
k++;
}
while (j < n2)
{
arr[k] = R[j];
j++;
k++;
}
}
void mergesortParallel(int a[],int l,int h){
 if(l<h){
 int mid = l+(h-l)/2;
 #pragma omp parallel sections
 {
 #pragma omp section
 mergesortParallel(a,l,mid);

 #pragma omp section
 mergesortParallel(a,mid+1,h);
 }
 merge(a,l,mid,h);
 }
}
void mergesortSerial(int a[],int l,int h){
 if(l<h){
 int mid = l+(h-l)/2;

 #pragma omp parallel sections
 {
 #pragma omp section
 mergesortSerial(a,l,mid);

 #pragma omp section
 mergesortSerial(a,mid+1,h);
 }
 merge(a,l,mid,h);
 }
}
int main(int argc,char *argv[]){
 int *a,num,i;
num=20;
a = (int *)malloc(sizeof(int)*num);
printf("array before sorting\n");
for(i=0;i<num;i++){
 a[i]= rand()%100;
printf("%d ",a[i]);
}
double start = omp_get_wtime();
mergesortSerial(a,0,num-1);
double end = omp_get_wtime();
 printf("\narray after sorting\n");
for(i =0;i<num;i++) printf("%d ",a[i]);
double val = end - start;
printf("\nTime for serial is:%f\n",val);
 start = omp_get_wtime();
 mergesortParallel(a,0,num-1);
 end = omp_get_wtime();
 val = end-start;
 printf("Time for parallel execution is %f\n",val);
}