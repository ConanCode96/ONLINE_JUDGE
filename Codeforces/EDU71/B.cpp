#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define X first
#define Y second
#define all(x) x.begin(), x.end()

const int MX = (int)1e5 + 10;
// const int mod = (int)1e9 + 7;

int main(int argc, char* argv[]){

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    int a[n][m], b[n][m];
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> a[i][j];
        }
    }

    memset(b, 0, sizeof b);

    vector<pair<int, int>> res;

    for(int i = 0; i + 1 < n; ++i){
        for(int j = 0; j + 1 < m; ++j){

            bool ok = true;
            for(int dx = 0; dx <= 1; dx++){
                for(int dy = 0; dy <= 1; ++dy){
                    ok &= a[i + dx][j + dy] == 1;
                }
            }
            if(ok){
                res.push_back({i, j});
                for(int dx = 0; dx <= 1; dx++){
                   for(int dy = 0; dy <= 1; ++dy){
                        b[i + dx][j + dy] = 1;
                    }
                }   
            }
        }
    }

    bool ok = true;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            ok &= a[i][j] == b[i][j];
        }
    }

    if(!ok) cout << -1 << endl;
    else{
        cout << res.size() << endl;
        for(auto &[x, y] : res)
            cout << x + 1 << " " <<  y + 1 << endl;
    }

    return 0;
}