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

const int N = 2e5 + 5;

ll n, k, mod = 1e7+7;
ll add(ll a, ll b){
    return (a%mod+b%mod)%mod;
}

ll mul(ll a, ll b){
    return (a%mod*b%mod)%mod;
}

ll fastPow(ll b, ll p){
    b%=mod;
    ll ans = 1;
    while(p){
        if(p&1) ans = mul(ans, b);
        b = mul(b, b);
        p>>=1;
    }
    return ans;
}

int main(){
    fastInputOutput();
    while(cin>>n>>k, n){
        ll ans = fastPow(n, k);
        ans = add(ans, fastPow(n, n));
        ans = add(ans, mul(2, add(fastPow(n-1, k), fastPow(n-1, n-1))));
        cout<<ans<<endl;
    }
    return 0;
}
