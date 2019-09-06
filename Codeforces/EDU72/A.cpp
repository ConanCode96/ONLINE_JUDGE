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
        int x, y, z;
        cin >> x >> y >> z;

        int l = x, r = l + z;
        while(l <= r){
            int xx = (l + r) / 2;
            int dx = xx - x;
            int yy = y + z - dx;
            if(xx > yy)
                r = xx - 1;
            else
                l = xx + 1;
        }

        // cout << r << endl;
        cout << z + 1 - (r - x + 1) << endl;
    }

    return 0;
}