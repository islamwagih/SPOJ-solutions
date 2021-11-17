#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define MOD(_a, _n) (((a%n)+n)%n)
#define getSize(_s) (int)_s.size()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

const int N = 1e7+5;
bool composite[N];
vector<int> specialPrimes;

bool goodPrime(int prime){
    ///goal to reach  x*x + y*y*y*y = prime
    for(ll y=0;y*y*y*y<=prime;y++){
        ll xx = prime - y*y*y*y;
        if(xx < 0) continue;
        ll x = sqrt(xx);
        if(x*x == xx) return true;
    }
    return false;
}

void sieve(){
    composite[0] = composite[1] = 1;
    for(ll i=2;i<N;i++){
        if(!composite[i]){
            if(goodPrime(i)) specialPrimes.push_back(i);
            for(ll j=i*i;j<N;j+=i){
                composite[j] = 1;
            }
        }
    }
}

int bs(int k){
    int low = -1, high = specialPrimes.size();
    while(low < high-1){
        int mid = low+(high-low)/2;
        if(specialPrimes[mid] <= k) low = mid;
        else high = mid;
    }
    return low+1;
}

int main(){

    fastInputOutput();
    sieve();
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        cout<<bs(n)<<endl;
    }

    return 0;
}
