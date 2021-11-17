#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define getSize(_s) (int)_s.size()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

set<int> elements;
int main(){
    fastInputOutput();
    int n, k;cin>>n>>k;
    for(int i=0;i<n;i++){
        int val;cin>>val;
        elements.insert(val);
    }
    int noOfPairs = 0;
    for(int number:elements){
        int first = number+k, second = number-k;
        if(elements.find(first) != elements.end()){
            noOfPairs++;
        }
        if(elements.find(second) != elements.end()){
            noOfPairs++;
        }
    }
    cout<<noOfPairs/2<<endl;
    return 0;
}

