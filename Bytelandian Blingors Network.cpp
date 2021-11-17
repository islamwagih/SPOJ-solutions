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

const int N = 2e4+5;
const int inf = 2e9+1;

int par[N], cnt[N];
vector<pair<int, pair<int, int>>> edgeList;

void init(int n){
    iota(par, par+n, 0);
    fill(cnt, cnt+n, 1);
}

int findPar(int u){
    if(u == par[u]) return u;
    return par[u] = findPar(par[u]);
}

bool join(int u, int v){
    u = findPar(u), v = findPar(v);
    if(u != v){
        if(cnt[u] < cnt[v]) swap(u, v);
        par[v] = u;
        cnt[u] += cnt[v];
        return true;
    }
    return false;
}


int main(){
    fastInputOutput();
    int t;cin>>t;
    while(t--){
        edgeList.clear();
        int n;cin>>n;
        init(n);
        for(int city=0;city<n;city++){
            string name;cin>>name;
            int chs;cin>>chs;
            while(chs--){
                int necity, cost;
                cin>>necity>>cost;
                edgeList.push_back({cost,{city, --necity}});
            }
        }
        sort(edgeList.begin(), edgeList.end());
        ll minCost = 0;
        for(auto weightedEdge:edgeList){
            if(join(weightedEdge.S.F, weightedEdge.S.S)){
                minCost += weightedEdge.F;
            }
        }
        cout<<minCost<<endl;
    }
    return 0;
}
