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

    

    int T;
    cin >> T;

    for(int t = 1; t <= T; ++t){
        int N, M, Q;
        cin >> N >> M >> Q;

        vector<int> sub(N + 1);
        
        for(int i = 0; i < M; ++i){

            int x;
            cin >> x;

            for(int j = 1; j * j <= x; ++j){
                if(x % j) continue;
                sub[j]++;
                if(j != x / j) sub[x / j]++;
            }
        }

        ll res = 0;

        while(Q--){
            int x;
            cin >> x;
            res += N / x - sub[x];
        }

        cout << "Case #" << t << ": " << res << "\n";
    }

    
    return 0;
}