#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define pll pair<ll,ll>
using namespace std;

ll p[1005];
ll n;

bool comp(pair<pll,pll> a, pair<pll,pll> b){
	return a.first.first<b.first.first;
}

void init(ll n){
	for(ll i=1;i<=n;i++){
		p[i]=i;
	}
}

ll root(ll a){
	while(p[a] != a){
		a=p[a];
	}
	return a;
}

void kruskal(vector<pair<pll,pll>> &arr, ll ans[]){

	ll a=1;
	pair<pll,pll> curr;
	for(ll i=0;i<arr.size();i++){
		curr = arr[i];

		if(root(curr.second.first) != root(curr.second.second)){
			ans[a++] = curr.first.second;
			// ll minn = min(root(curr.second.first), root(curr.second.second));
			p[root(curr.second.first)] = root(curr.second.second);
			//cout<<"a: "<<a-1<<" "<<ans[a-1]<<endl;
			//for(ll i=1;i<=n;i++) cout<<p[i]<<" ";
			//cout<<endl;
		}

		if(a>n) break;
	}
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll t;
	cin>>t;
	while(t--){
		ll m,q,a,b,w;
		cin>>n>>m>>q;

		init(n);

		vector<pair<pll,pll>> arr;
		for(ll i=0;i<m;i++){
			cin>>a>>b>>w;
			arr.push_back({{w,i+1},{a,b}});
		}

		sort(arr.begin(),arr.end(),comp);
		/*
		for(ll i=0;i<m;i++){
			cout<<arr[i].first.first<<" "<<arr[i].first.second<<endl;
		}
		//*/
		ll ans[n+1];

		kruskal(arr,ans);

		while(q--){
			cin>>a;
			cout<<ans[a]<<endl;
		}

	}

	return 0;
}