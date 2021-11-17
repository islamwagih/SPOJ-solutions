#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define MOD(_a, _n) (((a%n)+n)%n)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

const int N = 1e5 + 5;

int main(){
    fastInputOutput();
    int t;cin>>t;
    while(t--){
        int n, k;cin>>n>>k;
        deque<int> deq(n);
        for(int i=0;i<n;i++) cin>>deq[i];
        while(deq.size() >= k){
            int mx = -1;
            for(int i=0;i<k;i++){
                mx = max(mx, deq[i]);
            }
            cout<<mx<<' ';
            deq.pop_front();
        }
        cout<<endl;
    }
    return 0;
}
