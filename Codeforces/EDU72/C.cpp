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
        string s;
        cin >> s;
        int n = s.size();

        int res = 0;
        int acc[n] = {};
        for(int i = 0; i < n; i++){

            acc[i] = s[i] == '0';
            if(i > 0) acc[i] += acc[i - 1];

            int x = 0;

            for(int j = 0; j < 18; ++j){
                if(i - j < 0) break;
                x += (s[i - j] - '0') << j;
                res += x == (j + 1);
            }

            int rem = x - 18;
            if (rem > 0){
                int st = i - 18;
                int nd = st - rem;
                int rem_z = 0;
                if (st > 0)
                    rem_z = acc[st] - (nd < 0 ? 0 : acc[nd]);
                if (rem == rem_z) res++;
            }
        }

        cout << res << endl;
    }
    return 0;
}