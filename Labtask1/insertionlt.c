#include<stdio.h>
//sort the array using insertion sort and count insertion
int insertionsort(int Arr[],int n){
    int count;
    for(int i=1;i<n;i++){
        int key=Arr[i];
        int j=i-1;
        while(j>=0&&Arr[j]>key){
            Arr[j+1]=Arr[j];
            j=j-1;
            
        }
        Arr[j+1]=key;
        count ++;
    }
    printf("%d\n",count);
}
void print(int Arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",Arr[i]);
    }
}
int main(){
    int arr[6]={1,66,9,2,4,5};
    insertionsort(arr,6);
    print(arr,6);
    return 0;
}