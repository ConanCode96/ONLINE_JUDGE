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

    double a, b, x;
    cin >> a >> b >> x;

    const double PI = acos(-1);

    bool halfFull = 2 * x >= a * a * b;

    double angle = 0;

    if(halfFull){
        angle = atan(2 * (b - x / a / a) / a);
    }
    else{
        angle = atan(2 * x / a / b / b);
        angle = PI / 2 - angle;
    }
    
    cout << fixed << setprecision(6) << angle * 180 / PI << endl;

    return 0;
}