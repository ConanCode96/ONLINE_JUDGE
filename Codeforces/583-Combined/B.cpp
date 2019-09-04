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

    int b, g, n;
    cin >> b >> g >> n;

    int res = n + 1;
    
    if(n <= max(b, g)){
        res = min({n, b, g}) + 1;
    }
    else{
        res = 0;
        for(int i = 0; i <= b; ++i){
            res += n - i <= g;
        }
    }

    cout << res << endl;

    return 0;
}