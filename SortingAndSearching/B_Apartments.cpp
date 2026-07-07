// The answer is in the depth of five fathoms. Waiting to be retrieved.
#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> APL(n);// number of applicants
    for(ll i=0;i<n;i++){
        cin>>APL[i];
    }
    vector<ll> apartments(m);
    for(ll i=0;i<m;i++){
        cin>>apartments[i];
    }

    sort(APL.begin(),APL.end());
    sort(all(apartments));

    ll i=0,j=0;
    // i = applicant pointer, j = apartment pointer

    ll ans=0;

    while(i<n&&j<m){

        ll curL=APL[i]-k;
        ll curR=APL[i]+k;

        if(apartments[j]<curL){
            j++;
        }else if(apartments[j]>curR){
            i++;
        }else{
            ans++;
            i++;
            j++;
        }

    }

    cout<<ans<<endl;;

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.