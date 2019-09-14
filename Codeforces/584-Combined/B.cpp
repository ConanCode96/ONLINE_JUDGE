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


    int n;
    cin >> n;

    string s;
    cin >> s;

    int a[n], b[n];
    for(int i = 0; i < n; ++i){
        cin >> a[i] >> b[i];
    }


    int res = 0;
    for(int i = 0; i <= MX; ++i){
        int here = 0;
        for(int j = 0; j < n; ++j){
            if(i < b[j]) here += s[j] - '0';
            else{
                here += (((i - b[j]) / a[j]) & 1) ^ (s[j] - '0') ^ 1;
            }
        }
        res = max(res, here);
    }

    cout << res << endl;

    return 0;
}