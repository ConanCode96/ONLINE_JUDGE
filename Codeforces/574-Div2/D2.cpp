#include<bits/stdc++.h>
// #include"testlib.h"

using namespace std;

#define ll long long
#define X first
#define Y second
#define all(x) x.begin(), x.end()

const int MX = (int)1e5 + 10;
const int mod = 998244353;
// (int) 1e9 + 7;

ll pref[11][11], tfs[11][11], howMany[11];

int main(int argc, char* argv[]){

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    // registerGen(argc, argv, 1);

    int n;
    cin >> n;


    ll pw[22];
    pw[0] = 1;
    for(int i = 1; i <= 20; ++i){
        pw[i] = pw[i - 1] * 10 % mod;
    }

    ll sc[n][11];

    string s[n];
    for(int i = 0; i < n; ++i){
        cin >> s[i];
        int sz = (int)s[i].size();

        howMany[sz]++;

        ll prefix = 0;
        for(int j = 0; j < sz; ++j){

            int d = s[i][j] -'0';

            //add to pref[sz][prefix_so_far]
            prefix *= 10;
            prefix += d;
            prefix %= mod;
            pref[sz][j + 1] += prefix;
            pref[sz][j + 1] %= mod;
        }

        ll suffix = 0;
        int pos = 0;
        for(int j = sz - 1; j >= 0; --j, pos += 2){
            int d = s[i][j] - '0';

            suffix += d * pw[pos];
            suffix %= mod;

            sc[i][sz - j] = suffix;

            ll fsx = suffix * 10 % mod;
            tfs[sz][sz - j] += fsx;
            tfs[sz][sz - j] %= mod;
        }

    }

    ll res = 0;
    for(int i = 0; i < n; ++i){
        int scz = (int)s[i].size(); //second number size
        for(int fsz = 1; fsz <= 10; ++fsz){
            if(not howMany[fsz]) continue;
            int mn = min(scz, fsz);
            if(fsz < scz){
                ll pf = 0;
                int j = 0;
                while(j < scz - fsz){
                    pf *= 10;
                    pf += s[i][j] - '0';
                    pf %= mod;
                    j++;
                }
                res += (tfs[fsz][mn] + howMany[fsz] * (pf * pw[mn * 2] + sc[i][mn])) % mod;
            }
            else{
                res += (pref[fsz][fsz - scz] * pw[mn * 2] + tfs[fsz][mn] + howMany[fsz] * sc[i][mn]) % mod;
            }

            if(res >= mod) res -= mod;
        }
    }

    cout << res << endl;

    return 0;
}