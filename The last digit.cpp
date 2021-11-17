#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define MOD(_a, _n) (((a%n)+n)%n)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

ll fastPow(int b, int p, int m){
    b%=m;
    ll ans = 1;
    while(p){
        if(p&1) ans = (ans*b)%m;
        b = (b*b)%m;
        p>>=1;
    }
    return ans;
}

int main(){
    fastInputOutput();
    int t;cin>>t;
    while(t--){
        int b,p,m=10;
        cin>>b>>p;
        cout<<fastPow(b, p, m)<<endl;
    }
    return 0;
}
