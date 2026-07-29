// Match applicants with suitable apartments.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll x, n;
    cin >> x >> n;
    // Length And Count of lights

    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    multiset<ll> Lens; // 存所有长度集合
    set<ll> Sites;     // 存储所有灯的位置
    Sites.insert(0);
    Sites.insert(x); // 加入两个哨兵路灯
    Lens.insert(x);

    auto Insert = [&](const ll p) -> void
    {
        // 传入要插入的坐标p
        auto it = Sites.lower_bound(p);
        if (*it == p)
        {
            // 解出来坐标与p相等，就没有继续的必要
            return;
        }
        ll Left = *(prev(it));
        ll Right = *it;

        ll len = Right - Left;
        ll newLen1 = p - Left, newLen2 = Right - p;

        // Lens.erase(len);这样会按值删除，删除所有长度
        auto del = Lens.find(len); // 返回一个
        Lens.erase(del);
        Lens.insert(newLen1);
        Lens.insert(newLen2);

        Sites.insert(p);
    };

    for (const ll p : a)
    {
        Insert(p);
        cout << *Lens.rbegin() << ' ';
    }
    cout << endl;

    return 0;
}
