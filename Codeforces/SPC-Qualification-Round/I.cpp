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

    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i < n; ++i) cin >> a[i];

    map<int, int> mp;
    int b[n];
    for(int i = 0; i < n; ++i){
        cin >> b[i];
        mp[b[i]]++;
    }

    for(int i = 0; i < n; ++i){
        int chosen = mp.rbegin()->X;

        if((a[i] + chosen) & 1){
            int ox = mp.count(chosen - 1);
            if(ox) chosen--;
        }
        
        cout << (a[i] + chosen) / 2 << " \n"[i == n - 1];
        mp[chosen]--;
        // cout << chosen << endl;
        if(not mp[chosen]) mp.erase(chosen);
    }

    return 0;
}