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

    ll cur = x;
    ll ans = 0;

    deque<pair<ll, ll>> mins; // 存储当前窗口使之单调<val,id>
    mins.push_back({x, 1});

    for (ll i = 1; i <= n; i++)
    {
        if (i > 1)
        {
            cur = (a * cur + b) % c;
        }

        while (!mins.empty() && mins.back().first >= cur)
        {
            mins.pop_back();
        }
        mins.push_back({cur, i});

        while (!mins.empty() && mins.front().second <= i - k)
        {
            // 索引超过窗口大小
            mins.pop_front();
        }
        if (i >= k)
        {
            ans ^= mins.front().first;
        }
    }

    cout << ans << endl;

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.