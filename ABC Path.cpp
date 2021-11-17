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

const int N = 55;
const int inf = 2e9+1;

char matrix[N][N];
bool vis[N][N];
int n, m;
int dx[8] = {-1,+1,+0,+0,-1,+1,+1,-1};
int dy[8] = {+0,+0,+1,-1,+1,-1,+1,-1};

bool valid(int x, int y){
    bool c1 = x < n && x >= 0 && y < m && y >= 0;
    bool c2 = vis[x][y] == 0;
    return c1 && c2;
}

int mx = 0;
void dfs(int x, int y, int pathLen){
    vis[x][y] = 1;
    mx = max(mx, pathLen);
    //cout<<"curr at = "<<matrix[x][y]<<" curr length = "<<pathLen<<endl;
    for(int d=0;d<8;d++){
        int newx = x+dx[d];
        int newy = y+dy[d];
        if(valid(newx, newy) && (matrix[newx][newy] - matrix[x][y] == 1)){
            //cout<<"move from "<<matrix[x][y]<<" to "<<matrix[newx][newy]<<endl;
            dfs(newx, newy, pathLen+1);
        }
    }
    //cout<<"end at = "<<matrix[x][y]<<" curr path length = "<<pathLen<<endl;
}

void resetVisit(){
    for(int i=0;i<N;i++){
        for(int k=0;k<N;k++){
            vis[i][k] = 0;
        }
    }
}

int main(){
    fastInputOutput();
    int t = 1;
    while(cin>>n>>m, n){
        mx = 0;
        vector<pair<int, int>> As;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>matrix[i][j];
                if(matrix[i][j] == 'A') As.push_back({i, j});
            }
        }
        int ans = 0;
        for(auto& p:As){
            resetVisit();
            dfs(p.first, p.second, 1);
        }
        cout<<"Case "<<t++<<": "<<mx<<endl;
    }
    return 0;
}
