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

    int lfX = 0, rgX = 0;
    int sX = 0, sY = 0;
    for(int i = 0; i < n / 2; ++i){
        int j = n - i - 1;
        if(s[i] != '?')
            sX += s[i] - '0';
        else
            lfX++;

        if(s[j] != '?')
            sY += s[j] - '0';
        else
            rgX++;
    }

    int my_share = (lfX + rgX) >> 1;

    // cout << lfX << " " << rgX << endl;

    // use (a) ?s in the left half, (b) ?s in the right half

    bool ok = true; // I have to win in every possible set of questions I'm left with
    for(int a = 0; a <= min(lfX, my_share); ++a){
        int b = my_share - a;
        if(b > rgX) continue;

        bool here = false;

        //try making the left as small as possible, the right as high as possible
        {
            int lx = sX + a * 0;
            int ly = lx + (lfX - a) * 9;

            int rx = sY + b * 9;
            int ry = rx + (rgX - b) * 9;

            if(max(lx, rx) > min(ly, ry))
                here |= true;
        }

        //doing the reverse
        {
            int lx = sX + a * 9;
            int ly = lx + (lfX - a) * 9;

            int rx = sY + b * 0;
            int ry = rx + (rgX - b) * 9;

            if (max(lx, rx) > min(ly, ry))
                here |= true;
        }

        // cout << a << " " << b << " " << here << endl;
        ok &= here;
    }

    puts(ok ? "Monocarp" : "Bicarp");
    
    return 0;
}