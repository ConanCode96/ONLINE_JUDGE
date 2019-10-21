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

    // DP[cells][same_color_as_before?] 
    // 2nd dimension can be cancelled, they're the same (already remove)

    // calculating only for one color
    int dp[mx + 1][2]; 

    memset(dp, 0x00, sizeof dp);

    dp[1][0] = 1;

    dp[2][0] = 1;
    dp[2][1] = 1;

    for (int i = 3; i <= mx; ++i)
    {

        int &fs = dp[i][0];
        fs = (dp[i - 2][0] + dp[i - 2][1]) % mod; // assuming i - 2 is same color
        fs += dp[i - 2][0]; // assuming different color
        if(fs >= mod) fs-=mod;

        int &sc = dp[i][1];
        sc = dp[i - 2][0] + dp[i - 2][1]; // assuming i - 2 is different color
        if(sc >= mod) sc -= mod;
    
    }

    int at_least_one_hz_strip = (dp[n][0] + dp[n][1]) % mod;
    at_least_one_hz_strip %= mod;

    int at_least_one_vt_strip = (dp[m][0] + dp[m][1]) % mod; 
    at_least_one_vt_strip %= mod;

    // if all are alternating colors there're only two unique colorings, deduct the intesection
    int res = (at_least_one_hz_strip + at_least_one_vt_strip - 1) % mod;
    res *= 2;
    if(res >= mod) res -= mod;
    if(res < 0) res += mod;
    
    cout << res << endl;

    return 0;
}