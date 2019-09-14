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

    int a[n];
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    sort(a, a + n);

    vector<int> vis(n, 0);
    int res = 0;
    for(int i = 0; i < n; ++i){
        if(!vis[i]){
            res++;
            for(int j = i; j < n; ++j){
                if(a[j] % a[i] == 0) vis[j] = true;
            }
        }
    }

    cout << res << endl;

    return 0;
}