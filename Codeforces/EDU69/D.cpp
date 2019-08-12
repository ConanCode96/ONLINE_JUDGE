#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define X first
#define Y second
#define all(x) x.begin(), x.end()

const int MX = (int)1e5 + 10;
// const int mod = (int)1e9 + 7;

int main(int argc, char* argv[]){

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m, k;
    cin >> n >> m >> k;

    ll best[m];
    memset(best, 0x7f, sizeof best);
    
    ll sum = 0;
    ll res = 0;
    for(int i = 0, x; i < n; ++i){
        cin >> x;
        sum += x;
        ll so_far = sum - (i / m + 1LL) * k;
        for(int j = 0; j < m; ++j){
            res = max(res, so_far - best[j] - k * (j < i % m));
        }
        best[i % m] = min(best[i % m], so_far);
        res = max(res, so_far);
    }

    cout << res << endl;

    return 0;
}