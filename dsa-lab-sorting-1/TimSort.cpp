/*
    Problem Setter: Gunjan Chhablani
    Solution of: Arshdeep Singh
    Github Link: https://github.com/iamarshsingh/CS-F211
*/

#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

ll M=0,I=0;

int main() {
    ll t,r;
    cin>>t>>r;
    while(t--){
        M=0;I=0;
        ll n;
        cin>>n;
        deque<vector<ll>> finarr;
        vector<ll> arr(r);
        for(ll i=0;i<(n/r);i++){
            for(ll j=0;j<r;j++){
                cin>>arr[j];
                if(j>=1){
                    ll key=arr[j],ind=j-1;
                    while(ind>=0){
                        I++;
                        if(key<arr[ind]){
                            arr[ind+1]=arr[ind];
                            ind--;
                        }
                        else{
                            break;
                        }
                    }
                    arr[ind+1]=key;
                }
            }
            /*
            cout<<i<<" "<<I<<" : ";
            for(ll j=0;j<arr.size();j++){
                cout<<arr[j]<<" ";
            }
            cout<<endl;
            //*/
            finarr.push_back(arr);
        }
        if(n%r!=0){
            vector<ll> A(n%r);
            for(ll i=0;i<(n%r);i++){
                cin>>A[i];
                if(i>=1){
                    ll key=A[i],ind=i-1;
                    while(ind>=0){
                        I++;
                        if(key<A[ind]){
                            A[ind+1]=A[ind];
                            ind--;
                        }
                        else{
                            break;
                        }
                    }
                    A[ind+1]=key;
                }
            }
            finarr.push_back(A);
        }
        //cout<<finarr.size()<<endl;
        while(finarr.size()>1){
            ll vecs = finarr.size();
            for(ll i=0;i<vecs;i=i+2){
                if(i==vecs-1){
                    finarr.push_back(finarr.front());
                    finarr.pop_front();
                }
                else{
                    ll ai=0,bi=0;
                    vector<ll> Ai(finarr.front());
                    finarr.pop_front();
                    vector<ll> Bi(finarr.front());
                    finarr.pop_front();
                    ll lenA = Ai.size();
                    ll lenB = Bi.size();
                    vector<ll> tans;
                    while(ai<lenA && bi<lenB){
                        M++;
                        //cout<<"M: "<<Ai[ai]<<" "<<Bi[bi]<<endl;
                        if(Ai[ai]<Bi[bi]){
                            tans.push_back(Ai[ai]);
                            ai++;
                        }
                        else{
                            tans.push_back(Bi[bi]);
                            bi++;
                        }
                    }
                    while(ai<lenA){
                        tans.push_back(Ai[ai++]);
                    }
                    while(bi<lenB){
                        tans.push_back(Bi[bi++]);
                    }
                    finarr.push_back(tans);
                }
            }
        }
        cout<<I<<" "<<M<<endl;
        vector<ll> ans(finarr.front());
        for(ll i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
