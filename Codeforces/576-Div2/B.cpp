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

    ll L, H;
    cin >> H >> L;

    L *= L;

    double l = 0, r = 2e12;
    int it = 400;
    while(it--){
        double mid = (l + r) / 2;

        double hypox = L;
        double shouldBe = H * H + 2 * mid * H;
        if(shouldBe <= hypox) l = mid;
        else r = mid;
    }

    cout << fixed << setprecision(10) << (l + r) / 2.0 << endl;

    return 0;
}