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


void build(vector<int>& arr, vector<int>& tree, int v, int vl, int vr){
    if(vl == vr){
        tree[v] = arr[vl];
    }else{
        int mid = (vr+vl)/2;
        build(arr, tree, 2*v, vl, mid);
        build(arr, tree, 2*v+1, mid+1, vr);
        tree[v] = max(tree[2*v], tree[2*v+1]);
    }
}


int get(vector<int>& tree, int v, int vl, int vr, int l, int r){
    if(l > r) return 0; //must not effect the operation
    if(l == vl && r == vr) return tree[v];
    int mid = (vl+vr)/2;
    return max(get(tree, 2*v, vl, mid, l, min(r, mid)), get(tree, 2*v+1, mid+1, vr, max(l, mid+1), r));
}

void update(vector<int>& tree, int v, int vl, int vr, int indx, int val){
    if(vl == vr) tree[v] = val;
    else{
        int mid = (vl+vr)/2;
        if(indx <= mid) update(tree, 2*v, vl, mid, indx, val);
        else update(tree, 2*v+1, mid+1, vr, indx, val);
        tree[v] = max(tree[2*v], tree[2*v+1]);
    }
}

vector<int> arr, tree;
map<int, set<int>> record;
int main(){
    fastInputOutput();
    int n;cin>>n;
    arr = vector<int>(n);
    tree = vector<int>(4*n+5);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        record[arr[i]].insert(i);
    }
    build(arr, tree, 1, 0, n-1);
    int q;cin>>q;
    while(q--){
        char tp;cin>>tp;
        if(tp == 'U'){
            int i, x;cin>>i>>x;
            i--;
            record[arr[i]].erase(i);
            update(tree, 1, 0,n-1, i, x);
            arr[i] = x;
            record[arr[i]].insert(i);
        }else{
            int l, r;cin>>l>>r;
            l--, r--;
            int mx = get(tree, 1, 0, n-1, l, r);
            int mxIdx = *(record[mx].lower_bound(l));
            update(tree, 1, 0, n-1, mxIdx, 0);
            int secMx = get(tree, 1, 0, n-1, l, r);
            cout<<mx+secMx<<endl;
            update(tree, 1, 0, n-1, mxIdx, mx);
        }
    }
    return 0;
}
