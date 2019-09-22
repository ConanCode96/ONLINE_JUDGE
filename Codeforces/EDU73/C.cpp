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
        int c, m, x;
        cin >> c >> m >> x;

        int take = min({c, m, x}); // c m x
        c -= take;
        m -= take;
        x -= take;

        int l = 0, r = min(c, m);
        while(l <= r){
            int md = (l + r) / 2;
            int tmpC = c - md;
            int tmpM = m - md;
            if((tmpC + tmpM) >= md) l = md + 1;
            else r = md - 1;
        }

        int res = take + r;

        cout << res << endl;

    }

    return 0;
}