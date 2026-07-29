#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, t;
    cin >> n >> t; // Number of machines and required products.

    vector<ll> k(n);
    for (int i = 0; i < n; i++)
    {
        cin >> k[i];
    } // Time each machine needs for one product.

    sort(k.begin(), k.end());

    ll l = 0, r = k.back() * t; // The slowest machine gives a safe upper limit.

    auto check = [&](const ll &time) -> bool
    {
        ll cnt = 0; // Products made by this time.
        for (int num : k)
        {
            cnt+=time/num;
            if(cnt>=t){
                return true;
            }
        }
        if(cnt>=t){
            return true;
        }else{
            return false;
        }
    };

    while (l < r)
    {
        ll mid = l + (r - l) / 2;
        if(check(mid)){
            r=mid;
        }else{
            l=mid+1;
        }
    }
    cout<<r<<endl;

    return 0;
}
