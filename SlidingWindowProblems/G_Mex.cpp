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
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    set<ll> Mex; // 最小未出现非负整数
    unordered_map<ll, ll> cnt;

    auto Add = [&](const ll &x) -> void
    {
        if (cnt[x] == 0)
        {
            // 首次出现
            Mex.erase(x);
        }
        cnt[x]++;
    };

    auto Remove = [&](const ll &x) -> void
    {
        cnt[x]--;
        if (cnt[x] == 0)
        {
            Mex.insert(x);
        }
    };

    for (int i = 0; i <= k; i++)
    {
        Mex.insert(i);
    }

    for (int i = 1; i <= n; i++)
    {
        if (a[i] >= 0 && a[i] <= k)
        {
            Add(a[i]);
        }
        if (i > k && a[i - k] <= k)
        {
            Remove(a[i - k]);
        }
        if (i >= k)
        {
            cout << *Mex.begin() << ' ';
        }
    }
    cout << endl;

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.