#include<stdio.h>
#define cin(i)  scanf("%d",&i)
#define cend    printf("\n")
#define cout(i) printf("%d, ",i)
int partition(int arr[],int low,int high){
    int pivot = arr[high];
    int i = low - 1;
    for(int j=low;j<high;j++){
        if(arr[j] < pivot){
            i++;
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        } 
    }
    i++;
    int t = arr[i];
    arr[i] = arr[high];
    arr[high] = t;
    return i;
}
void q_sort(int arr[],int start, int end){
    if(start<end){
        int p = partition(arr,start,end);
        q_sort(arr,start,p-1);
        q_sort(arr,p+1,end);
    }
}
int main(){
    int arr[100];
    int n;
    cin(n);
    for(int i=0;i<n;i++) cin(arr[i]);
    for(int i=0;i<n;i++) cout(arr[i]);
    cend;
    q_sort(arr,0,n-1);
    for(int i=0;i<n;i++) cout(arr[i]);
    return 0;
}
