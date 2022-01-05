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


bool winState(string& board){
    bool row =
    (board[0] != '.' && board[0] == board[1] && board[1] == board[2]) ||
    (board[3] != '.' && board[3] == board[4] && board[4] == board[5]) ||
    (board[6] != '.' && board[6] == board[7] && board[7] == board[8]);

    bool col =
    (board[0] != '.' && board[0] == board[3] && board[3] == board[6]) ||
    (board[1] != '.' && board[1] == board[4] && board[4] == board[7]) ||
    (board[2] != '.' && board[2] == board[5] && board[5] == board[8]);

    bool dia =
    (board[0] != '.' && board[0] == board[4] && board[4] == board[8]) ||
    (board[2] != '.' && board[2] == board[4] && board[4] == board[6]);

    return row || col || dia;
}

void bfs(string& board){
    queue<pair<string, bool>> states;
    //1->X & 0->O
    states.push({".........", 1});
    while(states.size()){
        string currState = states.front().F;
        bool player = states.front().S;
        states.pop();
        if(currState == board){
            cout<<"yes\n";
            return;
        }else if(winState(currState)){
            continue;
        }else{
            for(int i=0;i<9;i++){
                if(currState[i]=='.'){
                    currState[i] = (player) ? 'X':'O';
                    if(currState[i] == board[i]) states.push({currState, player^1});
                    currState[i] = '.';
                }
            }
        }
    }
    cout<<"no\n";
}

int main(){
    fastInputOutput();
    int t;cin>>t;
    while(t--){
        string board = "";
        for(int i=0;i<3;i++){
            string row;cin>>row;
            board+=row;
        }
        bfs(board);
    }


    return 0;
}
