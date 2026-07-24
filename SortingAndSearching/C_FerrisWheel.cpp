// Put at most two people in each gondola.
#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,x;
    cin>>n>>x;
    vector<ll> Wei(n);
    for(ll i=0;i<n;i++){
        cin>>Wei[i];
    }

    sort(all(Wei));

    ll ans=0;
    ll l=0,r=n-1;

    while(l<=r){
        
        if(Wei[l]+Wei[r]<=x){
            l++;
        }
        r--;
        ans++;
    }
    cout<<ans<<'\n';
    return 0;
}
