// Answer each query with binary lifting.
#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

const ll LOG = 32;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,q;
    cin>>n>>q;

    vector<ll> t(n+1); // Next planet after one move.
    for(ll i=1;i<=n;i++){
        cin>>t[i];
    }

    // To[step][planet] is the planet reached after 2^step moves.
    vector<vector<ll>> To(LOG,vector<ll>(n+1,0));

    for(int i=1;i<=n;i++){
        To[0][i]=t[i];
    }

    for(int step = 1;step<LOG;step++){
        for(int u=1;u<=n;u++){
            To[step][u]=To[step-1][To[step-1][u]];
        }
    }

    while (q--)
    {
        
        ll x,k;
        cin>>x>>k;
        for(ll step=0;step<LOG;step++){
            if((k>>step)&1){
                x=To[step][x];
            }
        }
        cout<<x<<'\n';

    }
    

    return 0;
}
