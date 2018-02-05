/*
    Hossam ^_^
     ___     ___
    (^_^)   (^_^)
   /( | )\ /( | )\
     | |     | |
*/

#include <bits/stdc++.h>

using namespace std;

inline void prep(){
    cin.tie(0);cin.sync_with_stdio(0);
    #ifdef Cyborg101
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

#define X first
#define Y second
#define ll long long
#define all(x) x.begin(), x.end()

const int MX = 20002;
const int mood = ((int)1e9 + 7);

std::vector<vector<int>> g;
int pre[MX];
int low[MX];
int id[MX];
stack<int> stk;
int cntr, scc;

void tarjan(int x){

    stk.push(x);
    pre[x] = cntr++;
    low[x] = pre[x];

    for(auto y : g[x]){
        if(pre[y] == -1)
            tarjan(y);
        low[x] = min(low[x], low[y]); 
    }

    if(pre[x] == low[x]){ //component root
        while(true){
            int y = stk.top();
            stk.pop();
            low[y] = MX; //inf
            id[y] = scc;
            if(y == x) break;
        }
        scc++;
    }
}

int main(){

    prep();

    int tc;
    cin >> tc;

    while(tc--){

        int n, m;
        cin >> n >> m;

        g.clear();
        g.assign(n, vector<int>());

        for(int i = 0; i < m; ++i){
            int a, b;
            cin >> a >> b;
            --a, --b;
            g[a].push_back(b);
        }

        memset(pre, 0xff, sizeof pre);
        fill(id, id + n, 0);
        fill(low, low + n, 0);
        scc = 0, cntr = 0;

        for(int i = 0; i < n; ++i){
            if(pre[i] == -1)
                tarjan(i);
        }

        if(scc == 1) {
            cout << 0 << endl;
            continue;
        }

        std::vector<int> in(scc);
        std::vector<int> out(scc);
        for(int i = 0; i < n; ++i){
            for(auto j : g[i]){
                if(id[i] != id[j]){
                    in[id[j]]++;
                    out[id[i]]++;
                }
            }
        }

        int source = 0, sink = 0;
        for(int i = 0; i < scc; ++i){
            source += in[i] == 0;
            sink += out[i] == 0;
        }

        cout << max(source, sink) << endl;
    }

    return 0;
}   
