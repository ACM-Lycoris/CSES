#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin>>n;
    vector<ll> p(n);
    ll avg=0;
    for(ll i=0;i<n;i++){
        cin>>p[i];
        avg+=p[i];
    }   
    
    sort(p.begin(), p.end());

    ll mid = p[n / 2];

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += llabs(p[i] - mid);
    }

    cout<<ans<<'\n';

    return 0;
}
