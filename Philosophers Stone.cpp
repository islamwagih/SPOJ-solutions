#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define getSize(_s) (ll)_s.size()
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

inline void FIO(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

const int N = 1e2+9;
const int M = 2*N;
const int mod = 1e9+7;
const int OO = 0x3f3f3f3f;
const ll OOLL = 0x3f3f3f3f3f3f3f3f;


int n, m;
vector<vector<int>> grid, dp;

bool valid(int i, int j){
    return i >= 0 && j >= 0 && i < n && j < m;
}

int solve(int i, int j){
    if(valid(i, j)){
        if(~dp[i][j]) return dp[i][j];
        return dp[i][j] = grid[i][j]+max(solve(i+1, j), max(solve(i+1, j+1), solve(i+1, j-1)));
    }
    return 0;
}


int main(){
    FIO();
    int t;cin>>t;
    while(t--){
        cin>>n>>m;
        grid = vector<vector<int>>(n, vector<int>(m, 0));
        dp = vector<vector<int>>(n, vector<int>(m, -1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>grid[i][j];
            }
        }
        int ans = 0;
        for(int j=0;j<m;j++){
            ans = max(ans, solve(0, j));
        }
        cout<<ans<<endl;
    }
    return 0;
}
