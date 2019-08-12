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

    int n, k;
    cin >> n >> k;

    char a[n][n];
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> a[i][j];
        }
    }

    // if(n == 1){
    //     cout << 1 << endl;
    //     return 0;
    // }

    bool isRowWhiteLF[n][n] = {};
    bool isRowWhiteRG[n][n] = {};

    bool isColWhiteUP[n][n] = {};
    bool isColWhiteDN[n][n] = {};

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j)
            isRowWhiteLF[i][j] = (j > 0 ? isRowWhiteLF[i][j - 1] : true) & a[i][j] == 'W';
        for(int j = n - 1; j >= 0; --j)
            isRowWhiteRG[i][j] = (j < n - 1 ? isRowWhiteRG[i][j + 1] : true) & a[i][j] == 'W';
    }

    for(int j = 0; j < n; ++j){
        for(int i = 0; i < n; ++i)
            isColWhiteUP[i][j] = (i > 0 ? isColWhiteUP[i - 1][j] : true) & a[i][j] == 'W';
        for (int i = n - 1; i >= 0; --i)
            isColWhiteDN[i][j] = (i < n - 1 ? isColWhiteDN[i + 1][j] : true) & a[i][j] == 'W';
    }

    int accRow[n][n];
    int accCol[n][n];

    memset(accRow, 0, sizeof accRow);
    memset(accCol, 0, sizeof accCol);

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            int sameRow = j + k;
            int sameCol = i + k;

            accRow[i][j] = !isRowWhiteLF[i][n - 1] & (j > 0 ? isRowWhiteLF[i][j - 1] : true) & (sameRow < n ? isRowWhiteRG[i][sameRow] : true);
            accCol[i][j] = !isColWhiteUP[n - 1][j] & (i > 0 ? isColWhiteUP[i - 1][j] : true) & (sameCol < n ? isColWhiteDN[sameCol][j] : true); 
        }
    }


    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            accCol[i][j] += j > 0 ? accCol[i][j - 1] : 0;
            accRow[i][j] += i > 0 ? accRow[i - 1][j] : 0;
        }
    }

    int res = 0;
    for(int i = 0; i < n; ++i){
        res += isRowWhiteLF[i][n - 1];
        res += isColWhiteUP[n - 1][i];
    }

    int ans = res;

    for(int i = 0; i + k - 1 < n; ++i){
        for(int j = 0; j + k - 1 < n; ++j){
            int here = res;
            here += accRow[i + k - 1][j] - (i > 0 ? accRow[i - 1][j] : 0);
            here += accCol[i][j + k - 1] - (j > 0 ? accCol[i][j - 1] : 0);
            // if(k == 1) here = min(here, res + 1);
            ans = max(ans, here);
        }
    }

    cout << ans << endl;

    return 0;
}