#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define X first
#define Y second
#define all(x) x.begin(), x.end()

const int MX = (int)1e5 + 10;
// const int mod = (int)1e9 + 7;
const int mod = 998244353;

int main(){

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    int n;
    cin >> n;

    vector<pair<int, int>> a(n);
    int cnt[n + 1] = {};
    for(auto &[x, y] : a){
        cin >> x >> y;
        cnt[y]++;
    }

    sort(all(a));

    ll fact[n + 1];    fact[0] = 1;
    for(int i = 1; i <= n; ++i)
        fact[i] = fact[i - 1] * i % mod;

    ll res = fact[n];

    ll fs_sorted = 1;
    for(int i = 0; i < n;){
        int j = i;
        while(j < n && a[i].X == a[j].X) j++;
        fs_sorted *= fact[j - i];
        fs_sorted %= mod;
        i = j;
    }

    ll sc_sorted = 1;
    for(int i = 1; i <= n; ++i){
        (sc_sorted = (sc_sorted * fact[cnt[i]])) %= mod; 
    }

    bool bothSorted = 1;
    for(int i = 0; i + 1 < n; ++i){
        if(a[i].Y > a[i + 1].Y){
            bothSorted = 0;
            break;
        }
    }

    map<pair<int, int>, int> mp;
    for(auto &p : a) mp[p] ++;

    ll bothPerms = 1;
    for(auto &[_, y] : mp){
        (bothPerms *= fact[y]) %= mod;
    }

    res = res - fs_sorted - sc_sorted + (bothSorted ? bothPerms : 0);

    res %= mod;
    res += mod;
    res %= mod;

    cout << res << endl;

    return 0;
}