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

    int n, k;
    cin >> n >> k;
 
    int a[n];
    vector<int> diff;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        if(i > 0) diff.push_back(a[i] - a[i - 1]);
    }
 
    sort(all(diff));
 
    int del = k - 1;
    while(del--) diff.pop_back();
    ll res = accumulate(all(diff), 0LL);
 
    cout << res << endl;
 
    return 0;
}