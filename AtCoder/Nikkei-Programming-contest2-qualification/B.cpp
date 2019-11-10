#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define X first
#define Y second
#define all(x) x.begin(), x.end()

const int MX = (int)1e5 + 10;
// const int mod = (int)1e9 + 7;
const int mod = 998244353;

void add_self(int &x, int y){x += y; if(x >= mod) x -= mod;}
void sub_self(int &x, int y){x -= y; if(x < 0) x += mod;}
void mul(int &x, int y){x = x * 1LL * y % mod;}


int bp(int x, int exp){
    int res = 1;
    while(exp){
        if(exp & 1) mul(res, x);
        exp >>= 1;
        mul(x, x);
    }
    return res;
}

int main(){

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    int depth[n];
    int cnt[n + 1] = {};
    int mx = 0;
    for(int i = 0; i < n; ++i){
        cin >> depth[i];
        cnt[depth[i]]++;
        mx = max(mx, depth[i]);
    }

    int res = cnt[0] == 1 && depth[0] == 0;

    for(int i = 1; i <= mx; ++i) mul(res, bp(cnt[i - 1], cnt[i]));

    cout << res << endl;
    
    return 0;
}