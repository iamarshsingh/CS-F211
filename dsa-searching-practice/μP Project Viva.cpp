/*
    Problem Setter: Samarth Jain
    Solution of: Arshdeep Singh
    Github Link: https://github.com/iamarshsingh/CS-F211
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n,m;
ll times[100005];

ll check(ll t){
    ll ans = 0,temp;
    if(t<0) return 0;
    for(ll i=0;i<m;i++){
        temp = (t/(times[i])) + 1;
        ans += temp;
    }
    return ans;
}

int main() {
    int t;cin>>t;
    while(t--){
        cin>>m>>n;
        for(ll i=0;i<m;i++)cin>>times[i];
        ll l = 0;
        ll r = 1000000000000000000;
        ll mid,temp;
        while(l<r){
            mid = ((l+r)/2);
            temp = check(mid);
            //cout<<mid<<" "<<temp<<endl;
            if(temp < n){
                l = mid+1;
            }
            else r = mid;
        }
        //cout<<check(l)<<" "<<check(l-1)<<endl;
        temp = n-check(l-1);
        //cout<<l<<" "<<temp<<endl;
        for(ll i=0;i<m;i++){
            if(l%times[i]==0){
                temp--;
            }
            if(temp==0)
            {
                cout<<(i+1)<<endl;
                break;
            }
        }
    }
    return 0;
}