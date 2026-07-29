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
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    ll smallSize = k / 2;
    ll largeSize = k - smallSize;

    multiset<ll> large;
    multiset<ll> small;

    auto Adjust = [&]() -> void // Keep both sets balanced.
    {
        while (large.size() > largeSize) // Move extra values to the upper set.
        {
            auto it = prev(large.end());
            small.insert(*it);
            large.erase(it);
        }

        while (large.size() < largeSize && !small.empty()) // Fill the lower set.
        {
            auto it = small.begin();
            large.insert(*it);
            small.erase(it);
        }

        if (!large.empty() && !small.empty() &&
            *large.rbegin() > *small.begin())
        { // Keep every lower value at most every upper value.
            ll leftMax = *large.rbegin();
            ll rightMin = *small.begin();

            large.erase(prev(large.end()));
            small.erase(small.begin());

            large.insert(rightMin);
            small.insert(leftMax);
        }
    };

    auto Add = [&](ll x) -> void { // Add one value.
        if (large.empty() || x <= *large.rbegin())
        {
            large.insert(x);
        }
        else
        {
            small.insert(x);
        }

        Adjust(); // Restore balance after insertion.
    };

    auto Remove = [&](ll x) -> void { // Remove one value.
        auto it = large.find(x);

        if (it != large.end())
        {
            large.erase(it);
        }
        else
        {
            it = small.find(x);
            if (it != small.end())
            {
                small.erase(it);
            }
        }

        Adjust();
    };

    for (int i = 1; i <= n; i++)
    {
        Add(a[i]);

        if (i > k)
        {
            Remove(a[i - k]);
        }

        if (i >= k)
        {
            cout << *large.rbegin() << ' ';
        }
    }

    cout << '\n';
    return 0;
}
