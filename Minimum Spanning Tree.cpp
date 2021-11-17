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
const int inf = 2e9+1;

vector<pair<int, pair<int, int>>> edges;

int par[N], cnt[N];

void init(){
    iota(par, par+N, 0);
    fill(cnt, cnt+N, 1);
}

int findPar(int u){
    if(u == par[u]) return u;
    return par[u] = findPar(par[u]);
}

void join(int u, int v){
    u = findPar(u), v = findPar(v);
    if(u != v){
        if(cnt[u] < cnt[v]) swap(u, v);
        par[v] = u;
        cnt[u] += cnt[v];
    }
}

int main(){
    fastInputOutput();
    init();
    int n, m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int u, v, c;
        cin>>u>>v>>c;
        u--, v--;
        edges.push_back({c, {u, v}});
    }
    sort(edges.begin(), edges.end());
    ll cost = 0;
    for(auto pr:edges){
        int a = pr.second.first, b = pr.second.second, c = pr.first;
        if(findPar(a) != findPar(b)){
            join(a, b);
            cost += c;
        }
    }
    cout<<cost<<endl;
    return 0;
}
