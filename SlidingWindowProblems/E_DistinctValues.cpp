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

    unordered_map<ll, int> Cnt;
    Cnt.reserve(n * 2);

    ll Size=0;

    for (int i = 1; i <= n; i++)
    {
        if(Cnt[a[i]]==0){
            Size++;
        }
        Cnt[a[i]]++;

        if (i == k)
        {
            cout<<Size<<' ';
        }
        else if (i > k)
        {
            Cnt[a[i - k]]--;
            if(Cnt[a[i-k]]==0){
                Size--;
            }
            cout<<Size<<' ';

        }
    }

    cout << endl;
    return 0;
}
