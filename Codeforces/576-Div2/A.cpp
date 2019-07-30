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

    int n, x, y;
    cin >> n >> x >> y;

    int a[n];

    for(int i = 0; i < n; ++i) cin >> a[i];

    for(int i = 0; i < n; ++i){
        bool ok = true;
        for(int j = 1; j <= min(x, i); ++j) ok &= a[i] < a[i - j];
        for(int j = 1; j <= min(y, n - i - 1); ++j) ok &= a[i] < a[i + j];
        if(ok){
            cout << i + 1 << endl;
            return 0;
        }
    }

    return 0;
}