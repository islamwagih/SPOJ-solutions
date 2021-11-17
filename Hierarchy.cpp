#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define MOD(_a, _n) (((a%n)+n)%n)
#define getSize(_s) (int)_s.size()

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

const int mod = 1e9+7;
const int N = 1e5+5;
const int inf = 1e9;

vector<int> graph[N];
bool visited[N];
vector<int> topSort;
int parent[N];
void topologicalSort(int node){
    visited[node] = 1;
    for(int child:graph[node]){
        if(!visited[child]) topologicalSort(child);
    }
    topSort.push_back(node);
}

int main(){

    fastInputOutput();
    int n,m;cin>>n>>m;
    for(int v=1;v<=m;v++){
        int w;cin>>w;
        while(w--){
            int u;cin>>u;
            graph[v].push_back(u);
        }
    }
    for(int node=1;node<=n;node++){
        if(!visited[node]) topologicalSort(node);
    }

    int par = 0;
    for(int idx=topSort.size()-1;idx>=0;idx--){
        parent[topSort[idx]] = par;
        par = topSort[idx];
    }

    for(int node=1;node<=n;node++){
        cout<<parent[node]<<endl;
    }

    return 0;
}
