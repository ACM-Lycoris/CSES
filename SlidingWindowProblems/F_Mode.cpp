// Find the mode of every sliding window.
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

    vector<ll> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    
    unordered_map<ll,int> cnt;
    set<pair<ll,ll>> Rank;
    // Store each value as {-frequency, value}.
    // The first pair has the highest frequency and the smallest value.

    auto add = [&](const ll &x)->void{

        if(cnt[x]>0){
            Rank.erase({-cnt[x],x});
        }
        cnt[x]++;
        Rank.insert({-cnt[x],x});
    };

    auto remove = [&](const ll &x)->void{
        if(cnt[x]>0){
            Rank.erase({-cnt[x],x});
        }
        cnt[x]--;
        if(cnt[x]>0){
            Rank.insert({-cnt[x],x});
        }
    };

    
    for(int i=1;i<=n;i++){
        add(a[i]);

        if(i>k){
            remove(a[i-k]);
        }

        if(i>=k){
            cout<<Rank.begin()->second<<' ';
        }


    }

    cout<<endl;

    return 0;
}
