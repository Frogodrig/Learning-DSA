// You have prepared four problems. 
// The difficulty levels of the problems are A1,A2,A3,A4 respectively. 
// A problem set comprises at least two problems and no two problems in a problem set should have the same difficulty level. 
// A problem can belong to at most one problem set. 
// Output the maximum number of problem sets you can create using the four problems. 

// Sample Input 1

// 3
// 1 4 3 2
// 4 5 5 5
// 2 2 2 2

// Sample Output 1

// 2
// 1
// 0


#include <iostream>
using namespace std;

int main() {
	
	int t;
	
	cin>>t;
	
	while(t--){
	    int a[10]={0};
	    int temp=0;
	    bool triplet = false;
	    int distinct=0;
	    
	    for(int i=0;i<4;i++){
	        cin>>temp;
	        a[temp-1]++;
	    }
	    
	    for(int i=0;i<10;i++){
	        if(a[i]!=0){
	            distinct++;
	        }
	        if(a[i]==3){
	            triplet = true;
	        }
	    }
	    
	    if(distinct==4){
	        cout<<"2"<<endl;
	    }
	    else if(distinct==3){
	        cout<<"2"<<endl;
	    }
	    else if(distinct==2 && triplet == true){
	        cout<<"1"<<endl;
	    }
	    else if(distinct==2 && triplet == false){
	        cout<<"2"<<endl;
	    }
	    else{
	        cout<<"0"<<endl;
	    }
	}
	return 0;
}
