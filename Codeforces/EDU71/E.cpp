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
    
    vector<ll> fs(100), sc(100);
    iota(all(fs), 0);
    iota(all(sc), 0);

    ll msk = (1 << 7) - 1;

    for(int i = 0; i < 100; ++i){
        fs[i] = fs[i] << 7 | msk;
        sc[i] = msk << 7 | sc[i];
    }

    cout << "? ";
    for(auto &x : fs){
        cout << x << " ";
    }
    cout << endl;

    ll fs_res;
    cin >> fs_res;
    fs_res &= msk;
    
    cout << "? ";
    for(auto &x : sc){
        cout << x << " ";
    }
    cout << endl;

    ll sc_res;
    cin >> sc_res;
    sc_res &= msk << 7;

    ll res = (fs_res ^ msk) | (sc_res ^ (msk << 7));

    cout << "! " << res << endl;

    return 0;
}