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

    int t;
    cin >> t;

    /*
    LLLLL
    LLLLD
    RLLLL
    UUUUU */

    while(t--){
        int n, m, k;
        cin >> n >> m >> k;

        char s[n][m];
        for(int i = 0; i < k; ++i)
            s[i / m][i % m] = 'L';

        int row = 0;
        int col = -1;

        if(k){
            row = (k - 1) / m;
            col = (k - 1) % m;
        }

        if(m >= 2){
            if(col + 1 < m){
                if(col + 1 == m - 1){
                    if(row == n - 1){ // last row
                        cout << "NO\n";
                        continue;
                    }
                    s[row][col + 1] = 'D';
                }
                else{
                    s[row][col + 1] = 'R';
                    for(int j = col + 2; j < m; ++j)
                        s[row][j] = 'L';
                }
            } 
            for(int i = row + 1; i < n; ++i){
                s[i][0] = 'R';
                for(int j = 1; j < m; ++j)
                    s[i][j] = 'L';
            }
        }
        else{
            if(k)
                row++;
            if(row != n - 1){
                s[row][0] = 'D';
                for(int i = row + 1; i < n; ++i)
                    s[i][0] = 'U';
            }
            else{
                cout << "NO\n";
                continue;
            }
        }

        cout << "YES\n";
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j)        
                cout << s[i][j];
            cout << "\n";
        }
    }

    return 0;
}