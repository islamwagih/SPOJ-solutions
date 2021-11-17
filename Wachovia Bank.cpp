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

const int N = 1e4+5;
const int inf = 1e9+5;
const int M = 2*N;

int totalWeight, items;
vector<int> W, V;
vector<vector<int>> dp;

int solve(int i, int w){
    if(i == items) return 0;
    if(dp[i][w] != -1) return dp[i][w];
    int op1 = (w >= W[i]) ? V[i]+solve(i+1, w-W[i]):-1;
    int op2 = solve(i+1, w);
    return dp[i][w] = max(op1, op2);
}

int main(){
    fastInputOutput();
    int t;cin>>t;
    while(t--){
        cin>>totalWeight>>items;
        W = vector<int>(items);
        V = vector<int>(items);
        dp = vector<vector<int>>(items, vector<int>(totalWeight+1, -1));
        for(int i=0;i<items;i++) cin>>W[i]>>V[i];
        cout<<"Hey stupid robber, you can get "<<solve(0, totalWeight)<<".\n";
    }
    return 0;
}
