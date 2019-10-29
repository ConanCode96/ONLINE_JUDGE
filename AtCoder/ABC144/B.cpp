#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define X first
#define Y second
#define all(x) x.begin(), x.end()

const int MX = (int)1e5 + 10;
const int mod = (int)1e9 + 7;

int main(){

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    for(int i = 1; i <= 9; ++i){
        for(int j = 1; j <= 9; ++j){
            if(i * j == n){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;

    return 0;
}