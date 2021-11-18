#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define MOD(_a, _n) (((a%n)+n)%n)
#define getSize(_s) (int)_s.size()
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

const int N = 1e5+5;
const int inf = 1e9+5;
const int M = 2*N;

ll egcd(ll a, ll b, ll &x, ll &y){ /// ax + by = gcd(a,b)
    if(!b){
        x=1;
        y=0;
        return a;
    }
    ll g=egcd(b,a%b,y,x);
    y-=(a/b)*x;
    return g;
}

ll modInverse(ll a, ll m){ /// (a/b)%m = ((a%m)*(modInverse(b)%m))%m
    ll x,y,g;
    g=egcd(a,m,x,y);
    if(g>1)
        return -1;
    return (x+m)%m;
}

ll fixMod(ll a, ll m){
    return (a + m)%m;
}

ll pushBack(ll h, ll x, ll p, char ch){
    return (((h*x)%p)+ch)%p;
}

ll pushFront(ll h, ll xp, ll p, char ch){ // xp=XP[len]
    return (h+(xp*ch)%p)%p;
}

ll popBack(ll h, ll x, ll p, char ch){
    return (fixMod(h-ch,p)*modInverse(x,p))%p;
}

ll popFront(ll h, ll xp, ll p, char ch){ // xp=XP[len-1]
    return fixMod(h-((xp*ch)%p),p);
}

set<pair<ll, ll>> st;

int main(){
    fastInputOutput();
    int t;cin>>t;
    ll x = 1109, p1 = 1e9+7, p2 = 1e9+9;
    vector<ll> XP1(1e6+1), XP2(1e6+1);
    XP1[0] = XP2[0] = 1;
    for(int i=1;i<=1e6;i++){
        XP1[i]=(XP1[i-1]*x)%p1;
        XP2[i]=(XP2[i-1]*x)%p2;
    }
    while(t--){
        st.clear();
        int n, k;cin>>n>>k;
        string str;cin>>str;
        ll h1 = 0, h2 = 0;
        for(int i=0;i<k;i++){
            h1 = pushBack(h1, x, p1, str[i]);
            h2 = pushBack(h2, x, p2, str[i]);
        }
        st.insert({h1, h2});
        for(int i=k;i<n;i++){
            h1 = popFront(h1, XP1[k-1], p1, str[i-k]);
            h1 = pushBack(h1, x, p1, str[i]);
            h2 = popFront(h2, XP2[k-1], p2, str[i-k]);
            h2 = pushBack(h2, x, p2, str[i]);
            st.insert({h1, h2});
        }
       cout<<st.size()<<endl;
    }

    return 0;
}
