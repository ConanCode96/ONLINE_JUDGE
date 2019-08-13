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

    int n;
    cin >> n;

    ll a[n];
    ll gcd = 0;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        gcd = __gcd(gcd, a[i]);
    }

    // cout << gcd << endl;
    
    ll divs = 1;
    for(int i = 2; i * 1LL * i <= gcd; ++i){
        int cntr = 0;
        // ll t = gcd;
        while(gcd % i == 0){
            cntr++;
            gcd /= i;
        }
        divs *= (cntr + 1);
    }

    if(gcd != 1) divs *= 2;

    cout << divs << endl;
   
    return 0;
}