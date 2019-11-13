#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define X first
#define Y second
#define all(x) x.begin(), x.end()

const int MX = (int)1e5 + 10;
const int mod = (int)1e9 + 7;

void add_self(int &x, int y){x += y; if(x >= mod) x -= mod;}
void sub_self(int &x, int y){x -= y; if(x < 0) x += mod;}
void mul(int &x, int y){x = x * 1LL * y % mod;}

class SegmentTree{

inline int left (int p) { return p << 1; }
inline int right(int p) { return (p << 1) + 1; }

public:

vector<int> A, st; int n;

void build(int p, int L, int R){

	if(L == R) st[p] = A[L]; //value

	else{

        int mid = (L+R)>> 1;

        int l = left(p);
        int r = right(p);

        build(l, L, mid);
        build(r, mid + 1, R);

        int p1 = st[l];
        int p2 = st[r];

        st[p] = max(p1, p2);

	}
	
}

int rmq(int p, int L, int R, int i, int j){
 
	if(L > j || R < i) return -1; // non-existent
	if(L >= i && R <= j) return st[p];

	int mid = (L+R)>> 1;

	int l = left(p);
	int r = right(p);

	int p1 = rmq(l, L, mid, i, j);
	int p2 = rmq(r, mid + 1, R, i, j);

    return max(p1, p2);
}

SegmentTree(const vector<int> &A){
    this->A = A;
    this->n = A.size();
	st.assign(4*n, -1);
    build(1, 0, n - 1);
}

int rmq(int i, int j){ return i <= j ? rmq(1, 0, n - 1, i, j) : -1; }

};

int main(){

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i){
            cin >> a[i];
        }

        SegmentTree seg(a);

        vector<int> bestPower(n + 1, 0);

        int m;
        cin >> m;
        while(m--){
            int p, s;
            cin >> p >> s;
            bestPower[s] = max(bestPower[s], p);
        }

        for(int i = n - 1; i >= 1; --i)
            bestPower[i] = max(bestPower[i], bestPower[i + 1]);

        int res = 0;
        bool ok = true;
        int it = 0;
        while(it < n){
            int l = 1, r = n - it;
            while(l <= r){
                int md = (l + r) / 2;
                int mx_power = seg.rmq(it, it + md - 1);
                if(mx_power <= bestPower[md]) l = md + 1;
                else r = md - 1;
            }
            if(r == 0){
                ok = false;
                break;
            }
            res++;
            // cout << it << " " << r << endl;
            it += r;
        }

        if(ok) cout << res << "\n";
        else cout << -1 << "\n";

    }

    return 0;
}