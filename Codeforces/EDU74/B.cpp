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
        int n, r;
        cin >> n >> r;

        int a[n];
        for(int i = 0; i < n; ++i){
            cin >> a[i];
        }

        sort(a, a + n);

        int res = 0;
        int shift = 0;
        for(int i = n - 1; i >= 0;){
            if(a[i] - shift <= 0) break;
            int j = i;
            while(j >= 0 && a[i] == a[j]) j--;
            res++;
            shift += r;
            i = j;
        }

        cout << res << endl;
    }
    
    return 0;
}