#include<iostream>
using namespace std;

int main(){

    int n;cin>>n;
    int height[n];

    for(int i=0;i<n;i++){
        cin>>height[i];
    }

    int left = 0,right = n-1;
    int res = 0;
    int maxleft=0,maxright=0;

    while (left<=right)
    {
        if(height[left]<=height[right]){

            if(height[left>=maxleft]){
                maxleft=height[left];
            }
            else{
                res+=maxleft-height[left];
            }
            left++;
        }

        else{
            if(height[right]>=maxright){
                maxright = height[right];
            }
            else{
                res+=maxright-height[right];
            }
            right--;
        }
    }

    cout<<res;
    
    return 0;
}