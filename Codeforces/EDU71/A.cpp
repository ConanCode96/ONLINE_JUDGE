#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define X first
#define Y second
#define all(x) x.begin(), x.end()

const int MX = (int)1e5 + 10;
// const int mod = (int)1e9 + 7;

int main(int argc, char *argv[])
{

    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--)
    {
        int b, p, f;
        cin >> b >> p >> f;
        int h, c;
        cin >> h >> c;

        int res = 0;

        for (int i = 0; i <= min(p, b / 2); ++i)
        {
            int here = h * i + min(f, (b - 2 * i) / 2) * c;
            res = max(res, here);
        }

        cout << res << endl;
    }

    return 0;
}