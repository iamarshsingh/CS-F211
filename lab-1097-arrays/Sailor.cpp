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
        ll n;
        char w;
        cin>>n>>w;
        int grid[n][n]={0};
        for(int i=0;i<n;i++){
            grid[0][i] = i+1;
        }
        for(int i=1;i<n;i++){
            grid[i][n-1]=n+i;
        }
        /*
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        */
        int temp=(2*n);
        int x=n-2,y=n-1,turn=-1;
        while(temp<=(n*n)){
            grid[y][x] = temp++;
            //cout<<x<<" "<<y<<" "<<temp<<"     ";
            if(y==1 && turn==-1){
                x--;
                y--;
                turn=1;
            }
            else if(y==n-1 && turn==1){
                x--;
                y++;
                turn=-1;
            }
            if(turn==-1){
                y--;
            }
            if(turn==1){
                y++;
            }
        }
        /*
        cout<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        */
        ll ans=0;
        for(int i=n-1,j=0;i>=0 && j<n;i--,j++){
            //cout<<i<<" "<<j<<" "<<grid[i][j]<<"     ";
            ans = ans + grid[i][j];
        }
        //cout<<endl;
        cout<<ans<<endl;
    }
}