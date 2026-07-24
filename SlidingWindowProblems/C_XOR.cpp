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

    ll n,k;
    cin>>n>>k;
    
    ll x, a, b, c;
    cin >> x >> a >> b >> c;

    ll left = x;
    ll right = x;
    ll curXor = 0;
    ll ans = 0;

    for (int i = 1; i <= n; i++)
    {
        right = (i == 1 ? x : ((right * a + b) % c));

        if (i < k)
        {
            if(i==1){
                curXor=right;
            }else{
                curXor ^= right;
            }
        }
        else
        {
            curXor ^= right;
            if (i == k)
            {
                ans = curXor;
            }
            else
            {
                curXor ^= left;
                ans    ^= curXor;
                left    = (left * a + b) % c;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.