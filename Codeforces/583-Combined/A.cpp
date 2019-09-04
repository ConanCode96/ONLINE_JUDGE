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

    int n, d, e;
    cin >> n >> d >> e;

    int res = n;

    for(int y = 0; y <= n / (5LL * e); ++y){
        int rem = n - e * y * 5;
        res = min(res, rem % d);
    }

    cout << res << endl;

    return 0;
}