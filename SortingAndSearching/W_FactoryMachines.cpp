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

    ll n, t;
    cin >> n >> t; // 机器数量和产品数量

    vector<ll> k(n);
    for (int i = 0; i < n; i++)
    {
        cin >> k[i];
    } // 每个机器生产一个产品所需的时间

    sort(k.begin(), k.end());

    ll l = 0, r = k.back() * t; // 极端情况不会超过最慢的机器生产t个零件

    auto check = [&](const ll &time) -> bool
    {
        ll cnt = 0; // 这个时间t下能生产的产品数量
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
