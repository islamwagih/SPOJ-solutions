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

const int N = 2e5+10;
const int inf = 1e9+5;
const int M = 2*N;
const int mod = 1e9+7;


bool winState(string& grid){
    bool row =
    (grid[0] != '.' && grid[0] == grid[1] && grid[1] == grid[2]) ||
    (grid[3] != '.' && grid[3] == grid[4] && grid[4] == grid[5]) ||
    (grid[6] != '.' && grid[6] == grid[7] && grid[7] == grid[8]);

    bool col =
    (grid[0] != '.' && grid[0] == grid[3] && grid[3] == grid[6]) ||
    (grid[1] != '.' && grid[1] == grid[4] && grid[4] == grid[7]) ||
    (grid[2] != '.' && grid[2] == grid[5] && grid[5] == grid[8]);

    bool dia =
    (grid[0] != '.' && grid[0] == grid[4] && grid[4] == grid[8]) ||
    (grid[2] != '.' && grid[2] == grid[4] && grid[4] == grid[6]);

    return row || col || dia;
}

bool bfs(string targetGrid){
    string startGrid = ".........";
    queue<string> gridStates;
    gridStates.push(startGrid);
    //1 -> X && 0 -> O
    bool xTurn = 1;
    while(gridStates.size()){
        int sz = gridStates.size();
        char play = xTurn ? 'X':'O';
        while(sz--){
            string currGrid = gridStates.front();
            gridStates.pop();
            if(currGrid == targetGrid) return true;
            if(winState(currGrid)) continue;
            for(int i=0;i<9;i++){
                if(currGrid[i] == '.' && targetGrid[i] != '.' && targetGrid[i] == play){
                    currGrid[i] = play;
                    gridStates.push(currGrid);
                    currGrid[i] = '.';
                }
            }
        }
        xTurn ^= 1;
    }
    return false;
}

int main(){
    fastInputOutput();
    int t;cin>>t;
    while(t--){
        string grid = "";
        for(int i=0;i<3;i++){
            string row;cin>>row;
            grid+=row;
        }
        string ans = bfs(grid) ? "yes":"no";
        cout<<ans<<endl;
    }
    return 0;
}
