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

    int q;
    cin >> q;

    while(q--){
        int n;
        cin >> n;

        vector<pair<int, int>> v(n + 1);
        for(int i = 1; i <= n; ++i){
            cin >> v[i].X >> v[i].Y;
        }

        vector<vector<ll>> dp(n + 1, vector<ll>(3, 1e18));
        dp[0][0] = 0;
        dp[0][1] = 0;
        dp[0][2] = 0;
        for(int i = 1; i <= n; ++i){
            for(int dx = 0; dx <= 2; ++dx){
                for(int dy = 0; dy <= 2; ++dy){
                    if(v[i].X + dx == v[i - 1].X + dy) continue;
                    dp[i][dx] = min(dp[i][dx], dp[i - 1][dy] + dx * v[i].Y);
                }
            }
        }

        cout << min({dp[n][0], dp[n][1], dp[n][2]}) << "\n";
    }

    return 0;
}