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
        ll N, M;
        cin >> N >> M;

        ll a[N];
        for(int i = 0; i < N; ++i){
            cin >> a[i];
        }

        // sort(a, a + N);

        ll res = 0;
        ll cost = 0;

        int cnt[60] = {0};
        for(int bit = 0; bit < 50; ++bit){
            for(int i = 0; i < N; ++i){
                cnt[bit] += (a[i] >> bit) & 1;
            }
            if(2 * cnt[bit] >= N){
                res ^= 1LL << bit;
                cost += (N - cnt[bit]) * (1LL << bit);
            }
            else{
                cost += cnt[bit] * (1LL << bit);
            }
        }

        // cerr << res << " " << cost << "\n";

        if(cost > M) res = -1;
        else{
            for(int bit = 49; bit >= 0; --bit){
                if(2 * cnt[bit] < N){ //set it to one
                    int cur = cnt[bit];
                    int rem = N - cnt[bit];
                    if((cost + (rem - cur) * (1LL << bit)) <= M){
                        cost += (rem - cur) * (1LL << bit);
                        assert(((res >> bit) & 1) == 0);
                        res ^= (1LL << bit);
                    }
                }
            }
        } 

        cout << "Case #" << t << ": " << res << "\n";
    }

    
    return 0;
}