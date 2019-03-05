/*
    Problem Setter: Deep Chowdhury
    Solution of: Arshdeep Singh
    Github Link: https://github.com/iamarshsingh/CS-F211
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll check(ll n){
    ll ans = 0,temp;
    for(ll i=2;i<n;i++){
        temp = (n/(i*i*i));
        if(temp<1)break;
        ans += temp;
    }
    return ans;
}

int main() {
    int t;cin>>t;
    while(t--){
        ll m;
        cin>>m;
        
        ll l = 0;
        ll r = 10000000000000000;
        ll mid,temp,ans=-1;
        while(l<=r){
            mid = ((l+r)/2);
            temp = check(mid);
            //cout<<mid<<" "<<temp<<endl;
            if(temp==m){
                if(check(mid-1)<m){
                    ans = mid;
                    break;
                }
                else{
                    r = ((l+r)/2)-1;
                }
            }
            else if(temp > m){
                r = ((l+r)/2)-1;
            }
            else l = ((l+r)/2)+1;
        }
        cout<<ans<<endl;
    }
    return 0;
}