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

const int N = 1e3+5;
const int inf = 1e9+5;
const int M = 2*N;

int dp[50][50];
int arr[50];
int n;

int solve(int i, int j){
    if(i == n+1) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int op1 = (arr[i] > arr[j]) ? 1+solve(i+1, i):-inf;
    int op2 = solve(i+1, j);
    return dp[i][j] = max(op1, op2);
}

int main(){
    fastInputOutput();
    memset(dp, -1, sizeof dp);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    cout<<solve(1, 0)<<endl;
    return 0;
}
