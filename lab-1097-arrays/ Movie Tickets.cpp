/*
    Problem Setter: Deep Chowdhury
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
        int n;
        cin>>n;
        int arr[n],beh[n+1];
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]==-1){
                beh[0]=i+1;
            }
            else beh[arr[i]]=i+1;
        }
        //for(int i=0;i<n+1;i++)cout<<beh[i]<<" ";
        //cout<<endl;
        int temp = 0;
        while(n--){
            cout<<beh[temp]<<" ";
            temp = beh[temp];
        }
        cout<<endl;
    }
}