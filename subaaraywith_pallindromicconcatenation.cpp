#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

bool isPallindrome(int n){
    int temp = n, number = 0;

    while(temp > 0){
        number = number*10 + temp%10;
        temp = temp/10;
    }

    if(number == n){
        return true;
    }
    return false;
}


// int findPallindromicSubaaray(vector<int> arr, int k){
//     int num = 0;
//     for(int i=0;i<k;i++){
//         num = num*10 + arr[i];
//     }

//     if(isPallindrome(num)){
//         return 0;                                  
//     }

//      for(int j=k;j<arr.size();j++){
//          num = (num % (int)pow(10, k-1))*10 +arr[j]; //removing one digit from the start

//          if(isPallindrome(num)){
//              return j-k+1;
//          }
//      }

//     return -1;
// }


// int main(){

//     vector<int> arr = {2, 3, 5, 1, 1, 5};
//     int k =4;
//     int ans = findPallindromicSubaaray(arr, k);

//     if(ans == -1){
//         cout<<"Pallindromic Subaaray doesn't exist"<<"\n";
//     }
//     else{
//         for(int i = ans;i<ans+k;i++){
//             cout<<arr[i]<<" ";
//         }cout<<"\n";
//     }

//     return 0;
// }


// bool isPalindromicSubArraySizeKExists(int arr[],int n,int k){
//     int low = 0;
//     int high = -1;
//     deque<int> deq;
//     while(high<n){
//         int size = (high-low+1);
//         if(size==k){
            
//             auto start = deq.begin();
//             auto end = deq.end() - 1;
//             bool pal = true;
//             for(int i=0;i<deq.size()/2;i++){
//                 if((*start)!=(*end)){
//                     pal = false;
//                     break;
//                 }
//                 start++;
//                 end--;
//             }
//             if(pal)return true;
//             int x = arr[low];
//             while(x){deq.pop_front();x/=10;}
//             low++;
//         }
//         else if(size<k){
//             high++;
//             int x = arr[high];
//             int cnt = 0;
//             while(x){cnt++;x/=10;}
//             cnt = pow(10,cnt-1);
//             while(cnt){deq.push_back((arr[high]/cnt)%10);cnt/=10;}
//         }
//         else{
//             int x = arr[low];
//             while(x){deq.pop_front();x/=10;}
//             low++;
//         }
//     }
//     return false;
// }