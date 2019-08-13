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
   
    int q;
    cin >> q;

    while(q--){
        int n;
        cin >> n;

        int a[n];
        int idx[n];
        for(int i = 0; i < n; ++i){
            cin >> a[i];
            a[i]--;
            idx[a[i]] = i;
        }

        bool wise = true;
        for(int i = 0; i + 1 < n; ++i){
            wise &= idx[(i + 1) % n] == (idx[i] + 1) % n;
        }

        bool anti = true;
        for(int i = 0; i + 1 < n; ++i){
            anti &= idx[(i + 1) % n] == (idx[i] - 1 + n) % n;
        }

        puts(wise | anti ? "YES" : "NO");
    }

    return 0;
}