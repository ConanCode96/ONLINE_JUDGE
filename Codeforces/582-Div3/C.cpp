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
        ll n, m;
        cin >> n >> m;

        ll cnt = n / m;

        int rem[11] = {};
        for(int i = 1; i <= 10; ++i){
            rem[i] = m * i % 10;
            rem[i] += rem[i - 1];
        }

        ll res = (cnt / 10) * rem[10] + rem[cnt % 10];
        cout << res << endl;
    }

    return 0;
}