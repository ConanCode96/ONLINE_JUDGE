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


    int t;
    cin >> t;

    while(t--){
        int h, n;
        cin >> h >> n;

        int a[n + 1];
        for(int i = 0; i < n; ++i){
            cin >> a[i];
        }

        a[n] = 0;

        int res = 0;
        
        int current = h;
        
        int i = 0;

        while(i < n){
            while(i < n && current <= a[i]) i++;
            if(i < n && a[i + 1] != a[i] - 1)
                res++;
            current = a[i] - 1;
            // cout << current << " ";
        }
        // cout << endl;

        cout << res << endl;
    }
    
    return 0;
}