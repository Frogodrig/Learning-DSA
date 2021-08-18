// Gintoki has been very lazy recently and he hasn't made enough money to pay the rent this month. So the old landlady has given him a problem to solve instead, if he can solve this problem the rent will be waived. The problem is as follows:

// A triplet of integers (A,B,C)
// is considered to be special if it satisfies the following properties for a given integer N

// :

//     AmodB=C

// BmodC=0
// 1≤A,B,C≤N

// Example: There are three special triplets for N=3

// .

//     (1,3,1)

// is a special triplet, since (1mod3)=1 and (3mod1)=0
// .
// (1,2,1)
// is a special triplet, since (1mod2)=1 and (2mod1)=0
// .
// (3,2,1)
// is a special triplet, since (3mod2)=1 and (2mod1)=0

//     .

// The landlady gives Gintoki an integer N

// . Now Gintoki needs to find the number of special triplets. Can you help him to find the answer?
// Input Format

//     The first line of the input contains a single integer T

// denoting the number of test cases. The description of T
// test cases follows.
// The first and only line of each test case contains a single integer N

//     .

// Output Format

//     For each testcase, output in a single line the number of special triplets.

// Constraints

//     1≤T≤10

// 2≤N≤105

// Subtasks

// Subtask #1 (5 points): 2≤N≤103

// Subtask #2 (20 points): 2≤N≤104

// Subtask #3 (75 points): Original constraints
// Sample Input 1

// 3
// 3
// 4
// 5

// Sample Output 1

// 3
// 6
// 9


#include <iostream>
using namespace std;

int main() {
	
	
	int t;
	cin>>t;
	
	while(t--){
	    
	    int n;
	    cin>>n;
	    int count = 0;
	    
	    for(int C=1;C<=n;C++){
	        for(int B=C;B<=n;B+=C){
	            if(B%C==0){
	                for(int A=C;A<=n;A+=B){
	                    if(A%B==C){
	                        count++;
	                    }
	                }
	            }
	        }
	    }
	    cout<<count<<endl;
	}
	return 0;
}
