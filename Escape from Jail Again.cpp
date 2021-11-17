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

const int N = 1e2+5;
const int inf = 2e9+1;

char maze[N][N];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
/// first dimension if doors are closed the second one if doors are opened
int vis[2][N][N];
int n, m, vid;
int bfs(int i, int j){
    ///state of the door 0 -> closed, 1 -> opened
    bool doorState = 0;
    queue<pair<bool, pair<int, int>>> Q;
    Q.emplace(doorState, make_pair(i, j));
    int dis = 0;
    while(!Q.empty()){
        int sz = Q.size();
        while(sz--){
            doorState = Q.front().first;
            int x = Q.front().second.first, y = Q.front().second.second;
            //cout<<"curr at x = "<<x<<", y = "<<y<<" door state = "<<doorState<<endl;
            Q.pop();
            if(maze[x][y] == 'O') doorState = 1;
            if(maze[x][y] == 'C') doorState = 0;
            //cout<<"curr door state = "<<doorState<<endl;
            for(int k=0;k<4;k++){
                int newx = x+dx[k];
                int newy = y+dy[k];
                if(newx >= n || newx < 0 || newy < 0 || newy >= m) return dis+1;
                bool c1 = maze[newx][newy] != 'W';
                bool c2 = vis[doorState][newx][newy] != vid;
                bool c3 = maze[newx][newy] != 'D';
                if(c1 && c2 && ((doorState == 0 && c3)||(doorState == 1))){
                    Q.emplace(doorState, make_pair(newx, newy));
                    vis[doorState][newx][newy] = vid;
                }
            }
        }
        dis++;
    }
    return -1;
}

int main(){
    fastInputOutput();
    while(cin>>n>>m, ~n){
        vid++;
        int x, y;
        for(int i=0;i<n;i++){
            for(int k=0;k<m;k++){
                cin>>maze[i][k];
                if(maze[i][k] == 'H') x = i, y = k;
            }
        }
        vis[0][x][y] = vid;
        cout<<bfs(x, y)<<endl;
    }
    return 0;
}
