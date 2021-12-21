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

const int N = 1e6+5;
const int inf = 1e8+5;
const int M = 2*N;
const int mod = 1e9+7;

int frq[N];

struct Query{
    int l, r, i, bi;
    Query(int _l, int _r, int _i, int sqr) : l(_l), r(_r), i(_i), bi(_l/sqr){}
    bool operator<(const Query& b) const{
        if(bi != b.bi){
            return bi < b.bi;
        }
        return r < b.r;
    }
};

void remv(int i, vector<int>& arr, int& res){
    frq[arr[i]]--;
    if(frq[arr[i]] == 0) res--;
}

void add(int i, vector<int>& arr, int& res){
    frq[arr[i]]++;
    if(frq[arr[i]] == 1) res++;
}

vector<int> MoAlgorithm(vector<int>& arr, vector<Query>& queries){
    sort(queries.begin(), queries.end());
    int l = 1, r = 0, ans = 0;
    vector<int> output(queries.size());
    for(auto& q:queries){
        while(l < q.l) remv(l++, arr, ans);
        while(l > q.l) add(--l, arr, ans);
        while(r < q.r) add(++r, arr, ans);
        while(r > q.r) remv(r--, arr, ans);
        output[q.i] = ans;
    }
    return output;
}

int main(){
    fastInputOutput();
    int n;cin>>n;
    vector<int> arr(n);
    for(int& i:arr)cin>>i;
    int m;cin>>m;
    vector<Query> qs;
    int sqr = (int)ceil(sqrt(n));
    for(int i=0;i<m;i++){
        int l, r;cin>>l>>r;
        l--, r--;
        qs.push_back(Query(l, r, i, sqr));
    }
    auto ans = MoAlgorithm(arr, qs);
    for(auto& x : ans) cout<<x<<'\n';
    return 0;
}
