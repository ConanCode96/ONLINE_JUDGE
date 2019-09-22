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

    int q;
    cin >> q;

    while(q--){
        int n;
        cin >> n;

        int freq[30] = {};
        for(int i = 0; i < n; ++i){
            int x;
            cin >> x;
            int lsb = __builtin_ctz(x);
            freq[lsb]++;
        }

        for(int i = 0; i < 11; ++i){
            int take = freq[i] / 2;
            freq[i + 1] += take;
            freq[i] &= 1;
        }

        puts(freq[11] ? "YES" : "NO");
    }

    return 0;
}