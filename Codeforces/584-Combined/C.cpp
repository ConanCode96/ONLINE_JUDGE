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
        int n;
        cin >> n;

        string s;
        cin >> s;

        vector<int> pos[10];
        for(int i = 0; i < n; ++i){
            pos[s[i] - '0'].push_back(i);
        }

        vector<int> res(n, 0);

        int lst = -1;
        int taken = 0;
        int last = 0;

        for(int i = 0; i < 10; ++i){
            
            int nxt = -2;
            if (!pos[i].empty() && pos[i].back() > lst)
                nxt = pos[i].back();

            while(!pos[i].empty() && pos[i].back() > lst){
                res[pos[i].back()] = 1;
                pos[i].pop_back();
                taken++;
                last = i;
            }

            if(nxt != -2) lst = nxt;

            if (!pos[i].empty())
                break;
        }

        lst = -1;
        for(int i = last; i < 10; ++i){
            
            int nxt = -2;
            if (!pos[i].empty() && pos[i].back() > lst)
                nxt = pos[i].back();

            while(!pos[i].empty() && pos[i].back() > lst){
                res[pos[i].back()] = 2;
                pos[i].pop_back();
                taken++;
            }

            if(nxt != -2) lst = nxt;
        }

        if(taken != n) cout << "-";
        else 
            for(int i = 0; i < n; ++i)
                cout << res[i];
        cout << "\n";

    }

    return 0;
}