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

const int N = (1e4)+5;
vector<int> graph[N];
int visited[N];
void dfs(int node){
    visited[node] = 1;
    for(int child:graph[node]){
        if(!visited[child]){
            dfs(child);
        }
    }
}

int main(){

    fastInputOutput();
    int n, m;cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u, v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    if(n > m){
       dfs(1);
       for(int i=1;i<=n;i++){
            if(!visited[i]){
                cout<<"NO\n";
                return 0;
            }
       }
        cout<<"YES\n";

    }else{
        cout<<"NO\n";
    }
    return 0;

}
