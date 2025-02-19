#include<stdio.h>
//sort the given array by taking last element as pivot
int swap(int *x,int *y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
int partition(int A[],int lb,int hb){
    int pivot=A[hb];
    int start=hb-1;
    int end=lb;
    while(start>end){
        while(A[start]>=pivot&&start>lb){
            start--;
        }
        while(A[end]<pivot&&end<=hb){
            end++;
        }
        if(end<start){
            swap(&A[end],&A[start]);
        }
    }
    swap(&A[end],&A[hb]);
    return start;
}
void quicksort(int A[],int lb,int hb){
    if(lb<hb)
   { int loc=partition(A,lb,hb);
    quicksort(A,lb,loc-1);
    quicksort(A,loc+1,hb);}
}
int print(int A[],int n){
    for(int i=0;i<n;i++)
    {printf("%d ",A[i]);}
}
int main(){
    int A[6]={23,2,9,0,10,6};
    int size = sizeof(A) / sizeof(A[0]);
    quicksort(A,0,size-1);
    print(A,size);
}