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

    ll n;
    cin >> n;

    ll res = n;

    for(ll i = 1; i * i <= n; ++i){
        if(n % i) continue;
        ll j = n / i;
        res = min(res, i + j - 2);
    }

    cout << res << endl;

    return 0;
}