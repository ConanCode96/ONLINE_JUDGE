#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define X first
#define Y second
#define all(x) x.begin(), x.end()

const int MX = (int)5005;
// const int mod = (int)1e9 + 7;

vector<pair<int, int>> g[MX];
vector<int> res, vis;

void dfs(int x){
    vis[x] = 1; //still in stack
    for(auto &[y, id] : g[x]){
        if(vis[y] == 0){
            res[id] = 1;
            dfs(y);
        }
        else if(vis[y] == 1){
            res[id] = 2;
        }
        else if(vis[y] == 2){
            res[id] = 1;
        }
    }
    vis[x] = 2; //out of stack
}

int main(){

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; ++i){
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back({y, i});
    }

    res.resize(m);
    vis.resize(n);

    int k = 1;
    for(int i = 0; i < n; ++i) if(!vis[i]) dfs(i);

    cout << k + (count(all(res), 2) != 0) << endl;
    for(auto &id : res)
        cout << id << " ";
    cout << endl;

    return 0;
}