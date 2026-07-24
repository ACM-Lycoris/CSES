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

    vector<ll> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    
    unordered_map<ll,int> cnt;
    set<pair<ll,ll>> Rank;
    //Rank存储<-cnt[x],x>
    //Rank.begin()就是-cnt[x]最小，即是cnt[x]最大，且最靠前的数

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
// The answer is in the depth of five fathoms. And has always been her.