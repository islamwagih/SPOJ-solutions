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

int n;
vector<ll> dp, arr;

ll solve(int i){
    if(i >= n) return 0;
    if(dp[i] != -1) return dp[i];
    ll op1 = arr[i]+solve(i+2);
    ll op2 = solve(i+1);
    return dp[i] = max(op1, op2);
}

int main(){
    fastInputOutput();
    int t;cin>>t;
    for(int k=1;k<=t;k++){
        cin>>n;
        dp = vector<ll>(n, -1);
        arr = vector<ll>(n);
        for(auto& i:arr) cin>>i;
        cout<<"Case "<<k<<": "<<solve(0)<<endl;
    }
    return 0;
}
