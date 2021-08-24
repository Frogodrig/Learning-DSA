#include<iostream>
#include<vector>
#include<stack>

//most optimized solution which is as good as O(n) but difficult to explain

int main(){

    vector<int> histogram;
    stack<int> st;
    int n = histogram.size();
    int maxA=0;

    for(int i=0;i<=n;i++){
        while(!st.empty() && histogram[st.top()]>histogram[i]){
            int height = histogram[st.top()];
            st.pop();
            int width;
            if(st.empty()){
                width = i;
            }
            else{
                width = i - st.top()-1;
            }
            maxA = max(maxA,width*height);
        }
        st.push(i);
    }
    return maxA;
}

//less optimized but easier to explain, better than brute force though

int main(){

    vector<int> histogram;
    stack<int> st;
    int n = histogram.size();
    int maxA=0;
    int leftSmall[n], rightSmall[n];

    for(int i=0;i<n;i++){
        while(!st.empty() && histogram[st.top()]>histogram[i]){
            st.pop();
        }
        if(st.empty()){
            leftSmall[i]=0;
        }
        else{
            leftSmall[i]= st.top()+1;
        }
        st.push(i);
    }

    while(!st.empty()){
        st.pop();
    }

    for(int i=n-1;i>0;i--){
        while(!st.empty() && histogram[st.top()]>histogram[i]){
            st.pop();
        }
        if(st.empty()){
            rightSmall[i]=n-1;
        }
        else{
            rightSmall[i]= st.top()-1;
        }
        st.push(i);
    }

    for(int i=0;i<n;i++){
        maxA = max(maxA,heights[i]*(rightSmall[i]-leftSmall[i]+1));
    }
    return maxA;
}