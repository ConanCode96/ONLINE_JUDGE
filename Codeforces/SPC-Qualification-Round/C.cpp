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

    int n, m;
    cin >> n >> m;

    int a[n];
    int mx[n];
    vector<int> pos(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        --a[i];
        pos[a[i]] = i;
        mx[i] = a[i];
        if(i) mx[i] = max(mx[i - 1], mx[i]);
    }

    while(m--){
        int k, l;
        cin >> k >> l;
        int lst = k * l - 1;
        int at = pos[mx[lst]];
        cout << (at + 1 + k - 1) / k << "\n";
    }

    return 0;
}