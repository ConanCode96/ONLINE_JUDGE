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
    int loc[n + 1];
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        loc[a[i]] = i;
    }

    int lf = loc[n], rg = loc[n];
    for(int i = n - 1; i >= 1; --i){
        if(loc[i] == lf - 1) lf--;
        else if (loc[i] == rg + 1) rg++;
        else return puts("NO"), 0;
    }

    puts("YES");

    return 0;
}