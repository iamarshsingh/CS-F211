/*
    Problem Setter: Gunjan Chhablani
    Solution of: Arshdeep Singh
    Github Link: https://github.com/iamarshsingh/CS-F211
*/

#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define MOD 1000000007
using namespace std;

ld x,y,z,k;

ld deri(ld c){
    return (c/sqrt(x*x + c*c)) - ((k*(z-c))/sqrt(y*y + (z-c)*(z-c))) ;
}

ld dis(ld c){
    return sqrt(x*x + c*c) + sqrt(y*y + (z-c)*(z-c));
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>x>>y>>z>>k;
        ld lo = 0, mid, hi = z;
        ld diff = 0;
        cout<<setprecision(6)<<fixed;
        while(hi-lo>0.00001){
            mid = (lo+hi)/2;
            diff = deri(mid);
            //cout<<lower<<" "<<diff<<" "<<upper<<endl;
            if(diff<0){
                lo = mid;
            }
            else{
                hi = mid;
            }
        }
        cout<<dis(lo)<<endl;
    }
}