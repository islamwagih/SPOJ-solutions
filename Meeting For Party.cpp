#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define getSize(_s) (int)_s.size()
#define F first
#define S second


using namespace std;

typedef long long ll;
typedef unsigned long long ull;

inline void FIO(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

clock_t _stime, _etime;

inline void startTime(){
    _stime = clock();
}

inline void endTime(){
    _etime = clock();
}

inline void displayTime(){
    endTime();
    cerr<<(((double)_etime - _stime)/CLOCKS_PER_SEC)<<endl;
}


class Logger{
private:
    bool lock;
public:
    Logger(){
        lock = 0;
    }

    void on(){
        lock = 0;
    }

    void off(){
        lock = 1;
    }

    void bug(){
        if(!lock) cout<<endl;
    }

    template<typename T1, typename... T2>
    void bug(T1 a, T2... tail){
        if(!lock){
            cout<<a<<" ";
            bug(tail...);
        }
    }

};

Logger lg;

const int N = 2e5+5;
const int M = 2*N;
const int mod = 998244353;
const int OO = 0x3f3f3f3f;
const ll OOLL = 0x3f3f3f3f3f3f3f3f;

int di[4] = {+1,-1,+0,+0};
int dj[4] = {+0,+0,+1,-1};

int n, m, gn, gm;
vector<vector<char>> grid;
vector<pair<int, int>> starts;
vector<vector<int>> dist1, dist2, dist3;

bool valid(int i, int j)
{
    return i >= 0 && i < gn && j >= 0 && j < gm && grid[i][j] != '#';
}

void bfs(int i, int j, vector<vector<int>>& dist)
{
    dist[i][j] = 0;
    queue<pair<int, int>> q;
    q.push({i, j});
    while(q.size())
    {
        int x = q.front().F, y = q.front().S; q.pop();
        for(int k=0;k<4;k++)
        {
            int newx = x+di[k];
            int newy = y+dj[k];
            if(valid(newx, newy) && (dist[x][y]+1 < dist[newx][newy]))
            {
                dist[newx][newy] = dist[x][y] + 1;
                q.push({newx, newy});
            }
        }
    }
}


int32_t main()
{

    FIO();


#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    //startTime();

    
    int t;cin>>t;
    while(t--)
    {
        cin>>n>>m;
        //cout<<t<<' '<<n<<' '<<m<<endl;
        gn = n+2;
        gm = m+2;
        grid = vector<vector<char>>(gn, vector<char>(gm, '.'));
        starts = vector<pair<int, int>>();
        dist1 = vector<vector<int>>(gn, vector<int>(gm, OO));
        dist2 = vector<vector<int>>(gn, vector<int>(gm, OO));
        dist3 = vector<vector<int>>(gn, vector<int>(gm, OO));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>grid[i][j];
                if(grid[i][j] >= '1' && grid[i][j] <= '3')
                {
                    starts.push_back({i, j});
                }
            }
        }
        bfs(starts[0].F, starts[0].S, dist1);
        bfs(starts[1].F, starts[1].S, dist2);
        bfs(starts[2].F, starts[2].S, dist3);
        int ans = INT_MAX;
        for(int i=0;i<gn;i++)
        {
            for(int j=0;j<gm;j++)
            {
                if(grid[i][j] != '#')
                {
                    int mx = max({dist1[i][j], dist2[i][j], dist3[i][j]});
                    ans = min(ans, mx);
                }
            }
        }
        cout<<ans<<endl;
    }




    //displayTime();
    return 0;
}
