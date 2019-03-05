/*
    Problem Setter: Ravishankar Joshi
    Solution of: Arshdeep Singh
    Github Link: https://github.com/iamarshsingh/CS-F211
*/
#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,d;
        cin>>n>>d;
        ll arr[n];
        for(ll i=0;i<n;i++)cin>>arr[i];
        sort(arr,arr+n);
        ll *str,*fnd;
        ll ans = 0;
        for(ll i=0;i<n;i++){
            str = arr+i;
            fnd = lower_bound(str,arr+n,arr[i]+d);
            if(fnd==arr+n){
                ll temp = fnd-str+1;
                if(temp>ans) ans = temp;
                break;
            }
            else{
                ll temp = fnd-str+1;
                if(temp>ans) ans = temp;
            }
        }
        cout<<ans<<endl;
    }
}