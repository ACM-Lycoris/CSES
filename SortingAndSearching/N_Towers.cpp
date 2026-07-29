#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    vector<ll> a(n+1,-1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    multiset<ll> towerTops;

    ll cnt=1;
    towerTops.insert(a[1]);
    for(int i=2;i<=n;i++){
        auto it=towerTops.upper_bound(a[i]); // Find the first tower with a larger top.
        if(it == towerTops.end()){
            // Start a new tower.
            cnt++;
            towerTops.insert(a[i]);
        }else{
            // Put the cube on this tower.
            towerTops.erase(it);
            towerTops.insert(a[i]);
        }
    }
    
    cout<<towerTops.size()<<endl;;

    return 0;
}
