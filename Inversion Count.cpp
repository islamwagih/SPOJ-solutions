#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define MOD(_a, _n) (((a%n)+n)%n)
#define getSize(_s) (int)_s.size()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

ll merging(int arr[], int l1, int r1, int l2, int r2){
    vector<int> left, right;
    for(int i=l1;i<=r1;i++)
        left.push_back(arr[i]);
    for(int i=l2;i<=r2;i++)
        right.push_back(arr[i]);

    int idx = l1, l = 0, r = 0;
    ll inv = 0;
    while(idx <= r2){
        if(l == left.size()){
            arr[idx] = right[r++];
        }else if(r == right.size()){
            arr[idx] = left[l++];
        }else if(left[l] <= right[r]){
            arr[idx] = left[l++];
        }else{
            arr[idx] = right[r++];
            inv += left.size() - l;
        }
        idx++;
    }
    return inv;
}

ll mergeSort(int arr[], int l, int r){
    ll inv = 0;
    if(l < r){
        int mid = (l+r)/2;
        inv += mergeSort(arr, l, mid);
        inv += mergeSort(arr, mid+1, r);
        inv += merging(arr, l, mid, mid+1, r);
    }
    return inv;
}

const int N = (2e5)+5;
int arr[N];
int main(){

    fastInputOutput();
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        for(int i=0;i<n;i++) cin>>arr[i];
        ll invCount = mergeSort(arr, 0, n-1);
        cout<<invCount<<endl;
    }
    return 0;

}
