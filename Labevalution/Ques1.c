#include<stdio.h>
#include<stdbool.h>

int bubble(int Arr[],int N){
    bool flagged;
    for(int i=0;i<N-1;i++){
        for(int j=0;j<N-1-i;j++){
            if(Arr[j]>Arr[j+1]){
                int temp;
                temp=Arr[j+1];
                Arr[j+1]=Arr[j];
                Arr[j]=temp;
                flagged=true;
            }
        }
        if(flagged==false){
            break;
        }
    }
}
int print(int Arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d  ",Arr[i]);
    }
}
int main(){
    int Arr[6]={1,8,56,43,2,10};
    bubble(Arr,6);
    print(Arr,6);
}