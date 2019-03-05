/*
    Problem Setter: Sarthak Moorjani
    Solution of: Arshdeep Singh
    Github Link: https://github.com/iamarshsingh/CS-F211
*/

#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

bool comp(pair<ll,ll> a, pair<ll,ll> b){
    if(a.first==b.first) return a.second<b.second;
    return a.second<b.second;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        ll n, a, b;
        cin>>n;
        vector<pair<ll,ll>> arr(n);
        vector<pair<ll,ll>> ans;
        for(int i=0;i<n;i++){
            cin>>arr[i].first>>arr[i].second;
        }
        sort(arr.begin(),arr.end());
        a = arr[0].first;
        b = arr[0].second;
        for(int i=1;i<n;i++){
            if(arr[i].first<=b){
                b = max(arr[i].second,b);
            }
            else if(arr[i].first>b){
                ans.push_back(make_pair(a,b));
                a = arr[i].first;
                b = arr[i].second;
            }
        }
        ans.push_back(make_pair(a,b));
        for(int i=0;i<ans.size();i++){
            cout<<ans[i].first<<" "<<ans[i].second<<endl;
        }
    }
    return 0;
}