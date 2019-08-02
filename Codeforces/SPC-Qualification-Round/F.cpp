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

    int n, s;
    cin >> n >> s;

    int mn = n;

    for(int i = 0; i < n; ++i){
        int rem = s - i * 100;
        int sx = rem / (n - i);
        sx += (rem % (n - i)) != 0;
        if(sx < 50){
            mn = i;
            break;
        }
    }

    cout << min(n, s / 50) << " " << mn << endl;

    return 0;
}