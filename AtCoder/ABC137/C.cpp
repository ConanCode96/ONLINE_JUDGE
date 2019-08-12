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

    string a[n];
    map<string, int> cnt;
    for(int i = 0; i < n ; ++i){
        cin >> a[i];
        sort(all(a[i]));
        cnt[a[i]]++;
    }

    ll res = 0;
    for(auto &p : cnt){
        int y = p.Y;
        res += (y * (y - 1LL) / 2);
    }

    cout << res << endl;


 
    return 0;
}