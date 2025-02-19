#include<stdio.h>
//count the frequency of the elements in the arrays
int frequency(int arr[],int n,int x){
    int count=0;
    for(int i=0;i<n;i++){
        if (arr[i]==x){
            count++;
        }
    }
    return count;
}
int main(){
    int arr[]={1,2,2,3,4,6,4,4,6};
    int max=0; int freq[9],count;
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        freq[i]=-1;
    }
    for(int j=0;j<n;j++){
        count=1;
        for(int k=j+1;k<n;k++){
            if(arr[j]==arr[k]){
                count++;
                freq[k]=0;
            }

        }
        if(freq[j]!=0){
            freq[j]=count;
        }
    }
    for(int i=0;i<n;i++){
        if(freq[i]!=0){
            printf("Frequency of %d is= %d\n",arr[i],freq[i]);
        } 
    }
    for(int j=0;j<n;j++){
        if(freq[j]!=0)
        {printf("%d ",arr[j]);}
    }
    for(int k=0;k<n;k++){
        if(arr[k]>max){
            max=arr[k];
        }
    }
    printf("\n");
    printf("%d",max);
    
}