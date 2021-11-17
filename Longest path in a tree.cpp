#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define MOD(_a, _n) (((a%n)+n)%n)
#define getSize(_s) (int)_s.size()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}
const int N = 1e4 + 5;
vector<int> tree[N];
bool visited[N];
int dist[N];
void dfs(int node, int d){
    visited[node] = 1;
    dist[node] = max(dist[node], d);
    for(int child:tree[node]){
        if(!visited[child]){
            dfs(child, d+1);
        }
    }
}

int main(){

    fastInputOutput();
    int n;cin>>n;
    for(int i=1;i<n;i++){
        int u, v;cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    ///first run DFS from any arbitrary node
    dfs(1, 0);

    int maxDist = 0, endPoint = 0;
    for(int node=1;node<=n;node++){
        if(dist[node] > maxDist){
            maxDist = dist[node];
            endPoint = node;
        }
        visited[node] = 0;
    }

    ///run DFS from this endpoint
    dfs(endPoint, 0);

    for(int node=1;node<=n;node++){
        if(dist[node] > maxDist){
            maxDist = dist[node];
        }
    }

    cout<<maxDist<<endl;
    return 0;

}
