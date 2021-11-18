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

int main(){
    fastInputOutput();
    int t;
    ll x = 128, p = 1e9+7;
    vector<ll> XP(1e6+1);
    XP[0] = 1;
    for(int i=1;i<=1e6;i++){
        XP[i]=(XP[i-1]*x)%p;
    }
    while(cin>>t){
        string str, ptr;
        cin>>ptr>>str;
        vector<int> ans;
        int n = str.size(), m = ptr.size();
        ll hashVal = 0, orgHash = 0, cnt = 0;
        for(int i=0;i<min(n, m);i++){
            hashVal = pushBack(hashVal, x, p, str[i]);
            orgHash = pushBack(orgHash, x, p, ptr[i]);
        }
        if(n >= m){
            if(hashVal == orgHash){
                cnt++;
                cout<<0<<endl;
            }
            for(int i=m;i<n;i++){
                hashVal = popFront(hashVal, XP[m-1], p, str[i-m]);
                hashVal = pushBack(hashVal, x, p, str[i]);
                if(hashVal == orgHash){
                    cout<<i-m+1<<endl;
                    cnt++;
                }
            }
        }
        if(cnt == 0){
            cout<<"\n";
        }
    }

    return 0;
}
