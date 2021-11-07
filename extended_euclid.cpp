#include<iostream>
using namespace std;

struct triplet {

    int x,y,gcd;

};


//ax + by = gcd(a,b)
//ax + 0y = gcd(a,0)
// Since, gcd(a,0) = a

triplet extendedEuclid(int a, int b) {

    if(b == 0) {

        triplet ans;
        ans.x = 1;
        ans.gcd = a;
        ans.y = 0;
        return ans;
    }

    triplet smallAns = extendedEuclid(b,a%b);
    triplet ans;
    ans.x = smallAns.y;
    ans.gcd = smallAns.gcd;
    ans.y = smallAns.x - (a/b)*smallAns.y;
    return ans;
}

int multiplicativeModuloInverse(int a, int m) {

    triplet temp = extendedEuclid(a,m);
    return temp.x;

}


int main() {

    int a,b;
    cin>>a>>b;

    triplet ans = extendedEuclid(a,b);

    cout<<ans.gcd<<" "<<ans.x<<" "<<ans.y<<" "<<"\n";

    return 0;
}

//17*(-1) % 3
//-2 % 3 = (-2 + 3) % 3 = 1
//a%m = (a+m)%m