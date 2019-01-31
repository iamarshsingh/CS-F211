/*
    Problem Setter: Ishan Garg
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
        int n,time;
        cin>>n>>time;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int l=0,r=0,sum=0,maxx=0;
        while(l<n){
            while(sum+arr[r%n]<=time && r-l<n){
                sum = sum + arr[r%n];
                //cout<<sum<<endl;
                if(r-l+1>maxx)maxx=r-l+1;
                r++;
            }
            sum = sum - arr[l];
            l++;
        }
        cout<<maxx<<endl;
    }
}