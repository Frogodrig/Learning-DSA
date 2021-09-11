#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

//Time Complexity : O(n*sqrt(n))

bool isPerfect(int n){

    int sum = 1;

    for(int i =2;i<=sqrt(n);i++){
        if(n%i == 0){
            if(i == n/i){
                sum+=i;
            } else {
                sum+= i + n/i;
            }
        }
    }
    if(sum == n && n!=1){
        return true;
    }

    return false;

}

int maxSum(int arr[], int n, int k){
    if(n<k){
        cout<< "invalid Values"<<"\n";
        return -1;
    }

    int result = 0;
    for(int i=0;i<k;i++){
        result+=arr[i];
    }

    int sum = result;
    for(int i=k;i<n;i++){
        sum+=arr[i] - arr[i-k];
        result = max(result, sum);
    }

    return result;
}

int maxNumberOfPerfects(int arr[], int n, int k){

    for(int i=0;i<n;i++){
        if(isPerfect(arr[i])){
            arr[i]=1;
        } else {
            arr[i]=0;
        }
    }

    return maxSum(arr, n, k);
}


int main(){

    int arr[] = {28, 2, 3, 6, 496, 99, 8128, 24};
    int k =4;
    int n = 8;
    cout<<maxNumberOfPerfects(arr, n, k)<<"\n";

    return 0;
}