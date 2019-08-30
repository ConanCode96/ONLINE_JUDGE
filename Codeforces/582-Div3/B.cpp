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
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; ++i){
            cin >> a[i];
        }

        int mn = (int)1e6;
        int res = 0;
        for(int i = n - 1; i >= 0; --i){
            res += a[i] > mn;
            mn = min(mn, a[i]);
        }
        cout << res << endl;
    }

    return 0;
}