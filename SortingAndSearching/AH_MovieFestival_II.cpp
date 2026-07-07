// The answer is in the depth of five fathoms. Waiting to be retrieved.
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<pair<ll, ll>> movies(n);

    for (int i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        movies[i] = {b, a};
        // sort by end time, so first = end time (b), second = start time (a)
    }

    sort(movies.begin(), movies.end());

    multiset<ll> memberEnd;

    for (int i = 0; i < k; i++)
    {
        memberEnd.insert(0);
    }

    int ans = 0;

    for (auto [b, a] : movies)
    {
        auto it = memberEnd.upper_bound(a);

        if (it == memberEnd.begin())
        {
            continue;
        }

        --it;

        memberEnd.erase(it);
        memberEnd.insert(b);

        ans++;
    }

    cout << ans << '\n';

    return 0;
}