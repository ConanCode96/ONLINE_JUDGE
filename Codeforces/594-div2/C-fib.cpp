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

    // how to split n into sequences of only {1, 2}
    // DP[cells] 

    // calculating only for one color
    int dp[mx + 1]; 

    memset(dp, 0x00, sizeof dp);

    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= mx; ++i)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
        if(dp[i] >= mod) dp[i] -= mod;
    }

    int at_least_one_hz_strip = dp[n];

    int at_least_one_vt_strip = dp[m]; 

    // if all are alternating colors there're only two unique colorings, deduct the intesection
    int res = (at_least_one_hz_strip + at_least_one_vt_strip - 1) % mod;
    res *= 2;
    if(res >= mod) res -= mod;
    if(res < 0) res += mod;
    
    cout << res << endl;

    return 0;
}