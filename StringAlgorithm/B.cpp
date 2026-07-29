#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s,text;
    cin>>s>>text;

    ll n=s.length(),m=text.length();

    s=' '+s;
    text=' '+text;

    vector<int> Next(m+1,0);

    for(int i=2,j=0;i<=m;i++){
        while(j && text[i]!=text[j+1]){
            j=Next[j];
        }
        if(text[i]==text[j+1]){
            j++;
        }
        Next[i]=j;
    }

    ll ans=0;

    for(int i=1,j=0;i<=n;i++){
        while(j && s[i]!=text[j+1]){
            j=Next[j];
        }
        if(s[i]==text[j+1]){
            j++;
        }
        if(j==m){
            ans++;
            j=Next[j];
        }
    }

    cout<<ans<<endl;

    return 0;
}
