#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define X first
#define Y second
#define all(x) x.begin(), x.end()

const int MX = (int)1e5 + 10;
// const int mod = (int)1e9 + 7;

int main(){

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    char a[n][m];
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> a[i][j];
        }
    }

    bool reachableFrom00[n][m];
    memset(reachableFrom00, 0, sizeof reachableFrom00);

    queue<pair<int, int>> q;
    
    q.push({0, 0});

    while(!q.empty()){
        int x, y;
        tie(x, y) = q.front();
        q.pop();

        if (reachableFrom00[x][y])
            continue;

        reachableFrom00[x][y] = true;

        if (x < n - 1 && !reachableFrom00[x + 1][y] && a[x + 1][y] == '.')
            q.push({x + 1, y});
        if (y < m - 1 && !reachableFrom00[x][y + 1] && a[x][y + 1] == '.')
            q.push({x, y + 1});
    }


    q.push({n - 1, m - 1});

    bool vis[n][m];
    memset(vis, 0, sizeof vis);
    
    vector<pair<int, int>> dist[n + m];

    while(!q.empty()){
        int x, y;
        tie(x, y) = q.front();
        q.pop();

        if(vis[x][y]) continue;

        vis[x][y] = true;

        if(reachableFrom00[x][y])dist[x + y].push_back({x, y});

        if(x >= 1 && !vis[x - 1][y] && a[x - 1][y] == '.') q.push({x - 1, y});
        if(y >= 1 && !vis[x][y - 1] && a[x][y - 1] == '.') q.push({x, y - 1});
    }


    int res = n * m;

    for(int i = 1; i < n - 1 + m - 1; ++i)
        res = min(res, (int)dist[i].size());       
    
    cout << res << endl;

    return 0;
}