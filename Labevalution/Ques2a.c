#include<stdio.h>
//Quick sort starting element as pivot

int swap(int *x, int *y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
int partition(int A[],int ub,int hb){
    int pivot=A[ub];
    int start=ub+1;
    int end=hb;
    while(start<=end){
        while(A[start]<=pivot&& start<=hb){
            start++;
        }
        while(A[end]>pivot&& end>=ub){
            end--;
        }
        if(start<end){
            swap(&A[start],&A[end]);
        }
    }
    swap(&A[ub],&A[end]);
    return end;
}
int quicksort(int A[],int ub,int hb){
    if(ub<hb){
       int loc= partition(A,ub,hb);
        quicksort(A,ub,loc-1);
        quicksort(A,loc+1,hb);
    }

}
int main(){
    int arr[] = { 4, 2, 5, 3, 1 };
    int size = sizeof(arr) / sizeof(arr[0]);
    quicksort(arr,0,size-1);
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}