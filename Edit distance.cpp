#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define getSize(_s) (int)_s.size()
#define F first
#define S second


using namespace std;

typedef long long ll;
typedef unsigned long long ull;

inline void FIO(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

clock_t _stime, _etime;

inline void startTime(){
    _stime = clock();
}

inline void endTime(){
    _etime = clock();
}

inline void displayTime(){
    endTime();
    cerr<<(((double)_etime - _stime)/CLOCKS_PER_SEC)<<endl;
}


class Logger{
private:
    bool lock;
public:
    Logger(){
        lock = 0;
    }

    void on(){
        lock = 0;
    }

    void off(){
        lock = 1;
    }

    void bug(){
        if(!lock) cout<<endl;
    }

    template<typename T1, typename... T2>
    void bug(T1 a, T2... tail){
        if(!lock){
            cout<<a<<" ";
            bug(tail...);
        }
    }

};

Logger lg;

const int N = 2e5+5;
const int M = 2*N;
const int mod = 998244353;
const int OO = 0x3f3f3f3f;
const ll OOLL = 0x3f3f3f3f3f3f3f3f;

int n, m;
string a, b;
vector<vector<int>> dp;

int editDistance(int i, int j)
{
    if(i == n && j == m) return 0;
    if(i == n) return m-j;
    if(j == m) return n-i;
    if(dp[i][j] != -1) return dp[i][j];
    if(a[i] == b[j])
    {
        return dp[i][j] = editDistance(i+1, j+1);
    }
    int replace = 1+editDistance(i+1, j+1);
    int del = 1+editDistance(i+1, j);
    int del2 = 1+editDistance(i, j+1);
    return dp[i][j] = min({replace, del, del2});
}

int32_t main(){

    FIO();


#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    //startTime();
    int t;cin>>t;
    while(t--)
    {
        cin>>a>>b;
        n = a.size(), m = b.size();
        dp = vector<vector<int>>(n, vector<int>(m, -1));
        cout<<editDistance(0, 0)<<endl;
    }
    





    //displayTime();
    return 0;
}
