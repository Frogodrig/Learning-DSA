#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

void countSort(int arr[],int n){
    
    int k=arr[0];
    for(int i=0;i<n;i++){
        k=max(k,arr[i]);
    }
    int count[10]={0};
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }
    for(int i=1;i<=k;i++){
        count[i]+=count[i-1];
    }
    int b[10];
    for(int i=n-1;i>=0;i--){
        b[--count[arr[i]]]=arr[i];
    }
    for(int i=0;i<n;i++){
        arr[i]=b[i];
    }
    return;
}

int main(){

    int arr[]={0,1,1,1,2,5,6,3,2,5};
    countSort(arr,10);
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    return 0;
}