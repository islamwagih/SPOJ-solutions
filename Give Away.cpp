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

const int N = 4e5+5;
const int inf = 1e8+5;
const int M = 2*N;
const int mod = 1e9+7;

vector<int> arr;
vector<vector<int>> blocks;

int get(int l, int r, int c){
    int ans = 0, sqr = blocks.size();
    for(int i=l;i<=r;){
        if(i%sqr == 0 && i+sqr-1 <= r){
            ans += blocks[i/sqr].end() - lower_bound(blocks[i/sqr].begin(), blocks[i/sqr].end(), c);
            i+=sqr;
        }else{
            if(arr[i] >= c) ans++;
            i++;
        }
    }
    return ans;
}

void update(int index, int newVal){
    int sqr = blocks.size(), blockIdx = index/sqr;
    auto it = lower_bound(blocks[blockIdx].begin(), blocks[blockIdx].end(), arr[index]);
    if(it != blocks[blockIdx].end()){
        *it = newVal;
    }
    arr[index] = newVal;
    sort(blocks[blockIdx].begin(), blocks[blockIdx].end());
}

int main(){
    fastInputOutput();
    int n;cin>>n;
    arr = vector<int>(n);
    int sqr = (int)ceil(sqrt(n));
    blocks = vector<vector<int>>(sqr);
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++) blocks[i/sqr].push_back(arr[i]);
    for(int i=0;i<sqr;i++) sort(blocks[i].begin(), blocks[i].end());
    int q;cin>>q;
    while(q--){
        int type;cin>>type;
        if(type == 0){
            int l, r, c;cin>>l>>r>>c;
            cout<<get(l-1, r-1, c)<<endl;
        }else{
            int a, b;cin>>a>>b;
            a--;
            update(a, b);
        }
    }

    return 0;
}
