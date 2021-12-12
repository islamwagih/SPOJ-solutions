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
const int inf = 1e5+5;
const int M = 2*N;
const int mod = 1e9+7;


int Log(int x){
    return 31-__builtin_clz(x);
}

vector<vector<int>> buildTable(vector<int>& arr){
    int n = arr.size();
    vector<vector<int>> table(n, vector<int>(Log(n)+1));
    for(int i=0;i<n;i++) table[i][0] = arr[i];
    for(int j=1;(1<<j)<=n;j++){
        for(int i=0;i+(1<<j)-1<n;i++){
            table[i][j] = min(table[i][j-1], table[i+(1<<(j-1))][j-1]);
        }
    }
    return table;
}

int query(int l, int r, vector<vector<int>>& table){
    int len = r-l+1, mn = INT_MAX;
    int j = Log(len);
    return min(table[l][j], table[r-(1<<j)+1][j]);
}

int main(){
    fastInputOutput();
    int n;cin>>n;
    vector<int> arr(n);
    for(auto& i:arr) cin>>i;
    vector<vector<int>> table  = buildTable(arr);
    int q;cin>>q;
    while(q--){
        int l, r;cin>>l>>r;
        cout<<query(l, r, table)<<endl;
    }
    return 0;
}
