#include<stdio.h>
//writting movingg average
int main(){
    int arr[10],brr[10],n;
    scanf("%d",&n);
    for(int i=0;i<10;i++){
        scanf("%d",&arr[i]);
    }
    for(int j=0;j<=10-n;j++){
        int av=0;
        int sum=0;
        for(int k=0;k<j+n;k++){
            sum+=arr[k];
        }
        av=sum/n;
        brr[j]=av;
    }
    for(int i=0;i<10;i++){
        printf("%d  ",brr[i]);
    }
    return 0;
}