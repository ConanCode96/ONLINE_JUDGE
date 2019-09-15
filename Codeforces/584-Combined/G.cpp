#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define X first
#define Y second
#define all(x) x.begin(), x.end()

const int MX = (int)2e5 + 10;
// const int mod = (int)1e9 + 7;

vector<int> cnt(MX), lst(MX);

int main(){

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, q;
    cin >> n >> q;

    assert(q == 0);

    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        cnt[a[i]]++;
        lst[a[i]] = i;
    }

    int L = 0, R = 0, res = 0, mx = 0;
    for(int i = 0; i < n; ++i){

        R = max(R, lst[a[i]]);
        mx = max(mx, cnt[a[i]]);

        if(i == R){
            res += R - L + 1 - mx;
            L = R = i + 1;
        }
    }

    cout << res << endl;

    return 0;
}