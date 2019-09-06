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


    int t;
    cin >> t;

    while(t--){
        int n, x;
        cin >> n >> x;

        int a[n], b[n], idx[n];
        int mx = 0;
        for(int i = 0; i < n; ++i){
            cin >> a[i] >> b[i];
            idx[i] = i;
            mx = max(mx, a[i]);
        }

        sort(idx, idx + n, [&](int f, int g){
            if(b[f] - a[f] != b[g] - a[g])
                return b[f] - a[f] < b[g] - a[g];
            else
                return a[f] > a[g];
        });

        int res = -1;

        int bst = idx[0];
        int delta = b[bst] - a[bst];

        if(delta < 0){
            delta *= -1;
            // int l = 1, r = (x + delta - 1) / delta;
            // while(l <= r){
            //     int md = (l + r) / 2;
            //     int cur = x - (md - 1) * delta;
            //     if(cur - a[bst] <= 0)
            //         r = md - 1;
            //     else
            //         l = md + 1;
            // }
            // res = l;
            res = ((x - mx + delta - 1) / delta) + 1;
        }

        if(x - mx <= 0) res = 1;

        cout << res << endl;
    }

    return 0;
}