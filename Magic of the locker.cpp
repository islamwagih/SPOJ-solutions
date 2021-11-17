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

ll fastPow(ll b, ll p, ll m){
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
    ll mod = 1e9+7;
    int t;cin>>t;
    while(t--){
        ll n;cin>>n;
        if(n <= 3){
            cout<<n<<endl;
        }else if(n%3 == 0){
            cout<<fastPow(3, n/3, mod)<<endl;
        }else{
            ll threeCnt = (n-2)/3;
            ll twoCnt = (n-threeCnt*3)/2;
            ll ans = (fastPow(3, threeCnt, mod)%mod*fastPow(2, twoCnt, mod)%mod)%mod;
            cout<<ans<<endl;
        }
    }
    return 0;
}
