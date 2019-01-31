/*
    Problem Setter: Samarth Jain
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
        string s;
        cin>>s;
        int freq[26][26]={0};
        for(int i=0;i<s.length()-1;i++){
            freq[s[i]-'A'][s[i+1]-'A']++;
        }
        int maxx=0,ansi,ansj;
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                if(freq[i][j]>=maxx){
                    maxx=freq[i][j];
                    ansi=i;
                    ansj=j;
                }
            }
        }
        //cout<<ansi<<"  "<<ansj<<endl;
        cout<<string(1,'A'+ansi)+string(1,'A'+ansj)<<endl;
    }
}