#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define X first
#define Y second
#define all(x) x.begin(), x.end()

const int MX = (int)1e5 + 10;
const int mod = (int)1e9 + 7;

void add_self(int &x, int y){x += y; if(x >= mod) x -= mod;}
void sub_self(int &x, int y){x -= y; if(x < 0) x += mod;}
void mul(int &x, int y){x = x * 1LL * y % mod;}


int main(){

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i].X;
        a[i].Y = i;
    }

    sort(all(a));

    ll dp[n + 1];
    memset(dp, 0x7f, sizeof dp);
    dp[0] = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 3; j <= 5; ++j){
            if(i - j >= 0)
                dp[i] = min(dp[i], dp[i - j] + a[i - 1].X - a[i - j].X);
        }
    }

    cout << dp[n] << endl;


    vector<int> res(n);

    int it = n;
    int g = 1;
    while(it > 0){
        for(int j = 3; j <= 5; ++j){
            if(dp[it] == dp[it - j] + a[it - 1].X - a[it - j].X){
                for(int i = it; i > it - j; --i){
                    int idx = i - 1;
                    res[a[idx].Y] = g;
                }
                it -= j;
                break;
            }
        }
        g++;
    }

    cout << g - 1 << endl;

    for(auto &x : res) cout << x << " ";

    
    return 0;
}