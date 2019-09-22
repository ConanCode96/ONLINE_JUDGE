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

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cout << ((i + j) & 1 ? 'B' : 'W');
        }
        cout << "\n";
    }
    return 0;
}