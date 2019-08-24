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
        int n, a, b;
        cin >> n >> a >> b;

        string s;
        cin >> s;

        ll res = 0;
        ll pipes = n;
        ll heights = n + 1;

        vector<pair<int, int>> pos;
        for(int i = 0; i < n;){
            int j = i;
            while(j < n && s[j] == '1') j++;
            if(s[i] == '1') pos.push_back({i, j});
            else j++;
            i = j;
        }

        for(int i = 0; i < (int)pos.size(); ++i){

            heights += pos[i].Y - pos[i].X + 1;

            if(i + 1 < (int) pos.size()){

                int nxt_st = pos[i + 1].X;

                if(nxt_st - pos[i].Y > 1){
                    ll two_pipes_cost = 2LL * a;
                    ll seg_at_two = (nxt_st - pos[i].Y - 1) * 1LL * b;
                    res += min(two_pipes_cost, seg_at_two);
                }   
            }
        }

        pipes += 2 * !pos.empty(); //last one down

        res += pipes * a + heights * b;

        cout << res << endl;

    }


    return 0;
}