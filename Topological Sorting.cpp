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

const int N = 1e4+5;
vector<int> graph[N];
int ans[N];
int in[N];
int n, m, idx;
void bfs(){
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=1;i<=n;i++){
        if(in[i] == 0) pq.push(i), in[i]--;
    }
    while(pq.size()){
        int curr = pq.top();
        pq.pop();
        ans[idx++] = curr;
        for(int child:graph[curr]){
            in[child]--;
            if(in[child] == 0) pq.push(child), in[child]--;
        }
    }
}

int main(){

    fastInputOutput();
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u, v;cin>>u>>v;
        graph[u].push_back(v);
        in[v]++;
    }
    bfs();
    if(idx < n){
        cout<<"Sandro fails.\n";
    }else{
        for(int i=0;i<idx;i++){
            cout<<ans[i]<<' ';
        }
        cout<<endl;
    }
    return 0;

}
