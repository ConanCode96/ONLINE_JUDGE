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

    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<pair<int, int>> v;

    for(int i = 0; i < n;){
        int j = i;
        while(j < n && s[i] == s[j]) j++;
        int cnt = j - i;
        v.push_back({s[i] - 'A', cnt});
        i = j;
    }

    ll res = 0;

    int so_far[2] = {0, 0};
    int prv = 0;
    for(auto &[c, cnt] : v){
        // cout << c << " " << cnt << endl;
        res += cnt * (cnt - 1LL) / 2; //this group itself
        if(prv > 0)
            res += (prv - 1LL) * (cnt - 1LL); // AB
        res += cnt * 1LL * so_far[c]; // same type
        res += cnt * 1LL * (so_far[!c] - prv);
        so_far[c] += cnt;
        prv = cnt;
    }

    cout << res << endl;

    return 0;
}