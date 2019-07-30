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

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; ++i){
            cin >> a[i];
        }

        sort(a, a + n);

        int lf = a[n - 2];
        int it = n - 3;
        while(it >= 0 && it + 1 >= lf) it--;
        cout << it + 1 << "\n";
    }

    return 0;
}