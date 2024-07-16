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
const ll inf=1e9;
const ll N=1e5+7;
vector<ll> adjls[N];
vector<bool> vis(N,false);
void dfs(ll node){
    vis[node]=true;
    for(auto it:adjls[node]){
        if(!vis[it]){
            dfs(it);
        }
    }
}

void solve(){
    ll n,m;
    cin>>n>>m;
    f(i,0,m){
        ll a,b;
        cin>>a>>b;
        adjls[a].pb(b);
        adjls[b].pb(a);
    }
    vector<ll> ans;
    f(i,1,n+1){
        if(!vis[i]){
            ans.pb(i);
            dfs(i);
        }
    }
    if(sz(ans)==0){
        outs(0)
        return;
    }
    else{
        outs(sz(ans)-1)
        f(i,1,sz(ans)){
            outs2(ans[i-1],ans[i])
        }
        nline
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