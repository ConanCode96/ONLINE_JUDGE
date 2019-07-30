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

    int n, I;
    cin >> n >> I;

    I *= 8;
    
    vector<int> a(n);
    map<int, int> mp;
    for(auto &x : a){
        cin >> x;
        mp[x]++;
    }
    sort(all(a));
    a.resize(unique(all(a)) - a.begin());

    int sz = a.size();
    vector<int> cnt(sz);

    for(int i = 0; i < sz; ++i) cnt[i] = mp[a[i]];

    vector<int> lf(sz), rg(sz);
    partial_sum(all(cnt), lf.begin());
    partial_sum(cnt.rbegin(), cnt.rend(), rg.rbegin());

    // for(int i = 0; i < sz; ++i){
    //     cout << cnt[i] << " " << lf[i] << " " << rg[i] << endl;
    // }

    int msb = 31 - __builtin_clz(sz);

    int k = min(19, I / n);

    int K = 1 << k;

    int res = n;

    for(int i = 0; i < sz; ++i){
        int del = (i ? lf[i - 1] : 0) + (i + K < sz ? rg[i + K] : 0);
        res = min(res, del);
    }

    cout << (res != n? res: 0) << endl;

    return 0;
}