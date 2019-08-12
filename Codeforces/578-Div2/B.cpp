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

    int tc;
    cin >> tc;

    while(tc--){
        int n, m, k;
        cin >> n >> m >> k;

        int h[n];
        for(int i = 0; i < n; ++i){
            cin >> h[i];
        }

        bool ok = true;

        for(int i = 0; i + 1 < n; ++i){
            if(h[i + 1] - h[i] > k){
                int take = min(m, h[i + 1] - k - h[i]);
                m -= take;
                h[i] += take;
            }
            else{
                int lvl = max(0, h[i + 1] - k);
                m += h[i] - lvl;
                h[i] = lvl;
            }
            
            ok &= h[i + 1] - h[i] <= k; 
        }

        puts(ok ? "YES" : "NO");
    }
    
    return 0;
}