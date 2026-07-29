// Find the XOR of all sliding window minimums.
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

    ll ans = 0;
    ll nextX = x;

    deque<pair<ll, ll>> dq;

    for (int i = 1; i <= n; i++)
    {
        nextX = (i == 1 ? x : (a * nextX + b) % c);

        while (!dq.empty() && (dq.back().first >= nextX))
        {
            dq.pop_back();
        }

        dq.push_back({nextX, i});

        while (!dq.empty() && (dq.front().second <= i - k))
        {
            dq.pop_front();
        }

        if (i >= k)
        {
            ans ^= (dq.front().first);
        }
    }
    cout << ans << endl;

    return 0;
}
