/*
    Problem Setter: Samarth Jain
    Solution of: Arshdeep Singh
    Github Link: https://github.com/iamarshsingh/CS-F211
*/

#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

vector<ll> sieve(int n){
    vector<ll> ans;
    for(int i=0;i<n;i++){
        ans.push_back(1);
    }
    ans[0]=0;
    for(int i=2;i<n;i++){
        for(int j=i;j<n;j=j+i){
            ans[j] += i;
        }
    }
    //for(int i=0;i<n;i++)cout<<ans[i]<<" ";
    return ans;
}

int main(){
    int t;
    cin>>t;
    vector<ll> sums = sieve(1000005);
    ll pref[1000005]={0};
    for(int i=1;i<1000005;i++){
        pref[i] = pref[i-1]+sums[i];
    }
    while(t--){
        int l,r;
        cin>>l>>r;
        cout<<pref[r]-pref[l-1]<<endl;
    }
}