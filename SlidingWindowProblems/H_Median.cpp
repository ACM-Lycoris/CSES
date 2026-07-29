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

    auto Adjust = [&]() -> void // 维护函数
    {
        while (large.size() > largeSize) // 大维护
        {
            auto it = prev(large.end());
            small.insert(*it);
            large.erase(it);
        }

        while (large.size() < largeSize && !small.empty()) // 小维护
        {
            auto it = small.begin();
            large.insert(*it);
            small.erase(it);
        }

        if (!large.empty() && !small.empty() &&
            *large.rbegin() > *small.begin())
        { // 对顶维护
            ll leftMax = *large.rbegin();
            ll rightMin = *small.begin();

            large.erase(prev(large.end()));
            small.erase(small.begin());

            large.insert(rightMin);
            small.insert(leftMax);
        }
    };

    auto Add = [&](ll x) -> void { // 加元素
        if (large.empty() || x <= *large.rbegin())
        {
            large.insert(x);
        }
        else
        {
            small.insert(x);
        }

        Adjust(); // 加元素后维护
    };

    auto Remove = [&](ll x) -> void { // 删元素维护
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