#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define ff first
#define ss second
#define vi      vector<ll>
#define f(i,a,b)    for(ll i=(a);i<(b);i++)
#define fi(i,a,b)   for(ll i=(a);i>=(b);i--)
#define fc(i,a,b,c)    for(ll i=(a);i<(b);i+=(c))
#define sz(a)       ((ll)a.size())
#define llen(x)     (x.length())
#define in(v)       f(i,0,v.size()) cin>>v[i];
#define in2(x,y)    cin>>(x)>>(y);
#define outs(x)     cout<<(x)<<endl;
#define outs2(x,y)       cout<<(x)<<" "<<(y)<<endl;
#define outn(v)     f(i,0,v.size()) cout<<v[i]<<" ";
#define mii     map<ll,ll> 
#define vv(type,name,h,w,val) \
vector<vector<type>> name(h,vector<type>(w,val));
#define all(x)      x.begin(),x.end()
#define be begin()
#define fastio()    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pyes cout<<"Yes"<<endl
#define pn cout<<"No"<<endl
#define en end()
#define nline   cout<<endl;
#define vl vector<ll>
const int MOD = 1e9+7;
const ll inf=1e11;
const ll N=1e5+7;

void solve(){
    ll n,m; 
    cin>>n>>m;
    ll from,to,c;
    vector<pair<ll,ll>> adjls[n+1];
    f(i,0,m){
        cin>>from>>to>>c;
        adjls[from].pb({to,c});
    }
    vector<ll> dis(n+1,LLONG_MAX);
    dis[1]=0; // distance of starting node to itself
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push({0,1});
    while(!pq.empty()){
        ll tt=pq.top().ff;
        ll node=pq.top().ss;
        pq.pop();
        if(tt>dis[node])
        continue;
        for(auto it:adjls[node]){
            if(dis[it.ff]>dis[node]+it.ss){
                dis[it.ff]=dis[node]+it.ss;
                pq.push({dis[it.ff],it.ff});
            }
        }
    }   
    f(i,1,n+1){
        cout<<dis[i]<<" ";
    }
}
signed main() {
    fastio();
    ll t=1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}