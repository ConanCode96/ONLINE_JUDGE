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

    int T;
    cin >> T;

    for(int t = 1; t <= T; ++t){
        int n, k;
        cin >> n >> k;

        int a[n + 1];
        for(int i = 1; i <= n; ++i) cin >> a[i];

        int dp[n + 1][k + 2];
        memset(dp, 0x7f, sizeof dp);

        dp[0][0] = 0;

        for(int i = 1; i <= n; ++i){
            map<int, int> mp;
            for(int j = i; j >= 1; --j){

                mp[a[j]]++;
                int sz = i - j + 1;

                for(int kk = 1; kk <= k + 1; ++kk){
                
                    for(auto &p : mp){
                        int x = p.X;
                        int cnt = p.Y;
                        int cost = sz - cnt;
                        dp[i][kk] = min(dp[i][kk], cost + dp[j - 1][kk - 1]);
                    }
                }
            }
        }

        int res = dp[n][k + 1];
        for(int i = 1; i <= k + 1; ++i)
            res = min(res, dp[n][i]);
        
        cout << "Case #" << t << ": " << res << "\n";
    }

    return 0;
}