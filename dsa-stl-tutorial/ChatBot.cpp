#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        vector<int> out(26,0);
        for(int i=0;i<s.length();i++){
            out[s[i]-'a']++;
        }
        /*
        for(int i=0;i<26;i++){
            cout<<out[i]<<" ";
        }
        cout<<endl;
        //*/
        //cout<<s<<endl;
        int q;
        cin>>q;
        int ans=0;
        while(q--){
            string k;
            cin>>k;
            vector<int> in(26,0);
            for(int i=0;i<k.length();i++){
                in[k[i]-'a']++;
            }
            /*
            for(int i=0;i<26;i++){
                cout<<in[i]<<" ";
            }
            cout<<endl;
            //*/
            if(out==in){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}