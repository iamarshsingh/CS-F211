#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define pll pair<ll,ll>
using namespace std;

void dijkstra(vector<pll> arr[], ll dis[], ll p[] ,ll node, ll n, ll b){
    
    dis[node]=0;
    priority_queue<pll,vector<pll>, greater<pll>> pq;
    pq.push({0,1});

    while(!pq.empty()){
        pll a = pq.top();
        pq.pop();

        ll have = 0;
        ll curr = dis[a.second];
        ll temp = curr/b;
        if(temp%2==1){
            curr += (b - (curr - (temp*b)));
        }
        for(auto i: arr[a.second]){
            if(curr + i.first < dis[i.second]){
                p[i.second] = a.second;
                dis[i.second] = curr + i.first;
                pq.push({dis[i.second], i.second});
            }
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        ll n,m,b,x,y,w;
        cin>>n>>m>>b;

        vector<pll> arr[n+1];
        for(ll i=0;i<m;i++){
            cin>>x>>y>>w;
            arr[x].push_back({w,y});
            arr[y].push_back({w,x});
        }

        ll dis[n+1];
        ll p[n+1];
        for(ll i=1;i<=n;i++){
            dis[i] = 10000000000000000;
            p[i]=-1;
        } 

        dijkstra(arr,dis,p,1,n,b);

        cout<<dis[n]<<endl;
    }


    return 0;
}