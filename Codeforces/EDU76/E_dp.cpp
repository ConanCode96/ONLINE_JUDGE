#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define X first
#define Y second
#define all(x) x.begin(), x.end()

const int MX = (int)2e5 + 10;
const int mod = (int)1e9 + 7;

void add_self(int &x, int y){x += y; if(x >= mod) x -= mod;}
void sub_self(int &x, int y){x -= y; if(x < 0) x += mod;}
void mul(int &x, int y){x = x * 1LL * y % mod;}

int located[MX];
int dp[MX][3];

int calc(int problem, int idx, int n){

    if (idx == 3)
        return (int)1e9;

    if(problem == n + 1) return 0;

    int& res = dp[problem][idx];
    if(res != -1) return res;

    res = calc(problem, idx + 1, n); // consider it at the next idx

    res = min(res, calc(problem + 1, idx, n) + (located[problem] != idx));

    return res;
}

int main(){

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> v1(a), v2(b), v3(c);
    for(auto &x : v1) cin >> x, located[x] = 0;
    for(auto &x : v2) cin >> x, located[x] = 1;
    for(auto &x : v3) cin >> x, located[x] = 2;

    memset(dp, 0xff, sizeof dp);

    cout << calc(1, 0, a + b + c) << endl;

    return 0;
}