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
    // Track light positions and segment lengths.

    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    multiset<ll> Lens; // Lengths of all road segments.
    set<ll> Sites;     // Positions of all traffic lights.
    Sites.insert(0);
    Sites.insert(x); // Add two border lights.
    Lens.insert(x);

    auto Insert = [&](const ll p) -> void
    {
        // Insert a light at position p.
        auto it = Sites.lower_bound(p);
        if (*it == p)
        {
            // Stop if a light already exists here.
            return;
        }
        ll Left = *(prev(it));
        ll Right = *it;

        ll len = Right - Left;
        ll newLen1 = p - Left, newLen2 = Right - p;

        // erase(len) would remove every segment with this length.
        auto del = Lens.find(len); // Find one matching segment.
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
