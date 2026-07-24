// The answer is in the depth of five fathoms. Waiting to be retrieved.
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

inline void optimize()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    optimize();

    ll n, k;
    cin >> n >> k;
    ll x, a, b, c;
    cin >> x >> a >> b >> c;

    deque<pair<ll,ll>> dq;

    ll cur = x;
    ll ans = 0;
    ll nextX;
    for (ll i = 1; i <= n; i++)
    {
        nextX = (i == 1 ? x : (nextX * a + b) % c);

        while(i<=n && (!dq.empty() && dq.back().first >= nextX)){
            dq.pop_back();
        }

        dq.push_back({nextX,i});

        while(!dq.empty() && dq.front().second <= i-k){
            dq.pop_front();
        }

        if(i==k){
            ans=(dq.front().first);
        }else if(i>k){
            ans^=(dq.front().first);
        }

    }
    cout<<ans<<endl;

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.