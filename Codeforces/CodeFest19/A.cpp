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
        int a, b, n;
        cin >> a >> b >> n;

        int res[3] = {a, b, a ^ b};

        cout << res[n % 3] << endl;
    }

    return 0;
}