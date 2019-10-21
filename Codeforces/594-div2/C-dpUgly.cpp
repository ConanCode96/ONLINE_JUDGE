#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define X first
#define Y second
#define all(x) x.begin(), x.end()

const int MX = (int)1e5 + 10;
const int mod = (int)1e9 + 7;

int main(){

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    int mx = max(n, m);

    // DP[cells][color][same_color_as_before?] 
    // 2nd dimension can be cancelled, they're the same
    int dp[mx + 1][2][2]; 

    memset(dp, 0x00, sizeof dp);

    dp[1][0][0] = dp[1][1][0] = 1;

    dp[2][0][0] = dp[2][1][0] = 1;
    dp[2][0][1] = dp[2][1][1] = 1;

    for (int i = 3; i <= mx; ++i)
    {
        for(int x : {0, 1}){
            int &fs = dp[i][x][0];
            fs = dp[i - 2][x][0] + dp[i - 2][x][1];
            if(fs >= mod) fs-=mod;
            fs += dp[i - 2][!x][0];
            if(fs >= mod) fs-=mod;

            int &sc = dp[i][x][1];
            sc = dp[i - 2][!x][0] + dp[i - 2][!x][1];
            if(sc >= mod) sc -= mod;
        }
    }

    int at_least_one_hz_strip = (dp[n][0][0] + dp[n][0][1]) % mod + (dp[n][1][0] + dp[n][1][1]) % mod;
    at_least_one_hz_strip %= mod;

    int at_least_one_vt_strip = (dp[m][0][0] + dp[m][0][1]) % mod + (dp[m][1][0] + dp[m][1][1]) % mod;
    at_least_one_vt_strip %= mod;

    int res = at_least_one_hz_strip + at_least_one_vt_strip - 2;
    if(res >= mod) res -= mod;
    if(res < 0) res += mod;
    
    cout << res << endl;

    return 0;
}