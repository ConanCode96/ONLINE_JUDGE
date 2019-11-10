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

int main(){

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<pair<int, int>> A(n), B(n);
    int id = 0;
    for(auto &p : A){
        cin >> p.X;
        p.Y = id++;
    }
    id = 0;
    for(auto &p : B){
        cin >> p.X;
        p.Y = id++;
    }

    sort(all(A));
    sort(all(B));

    for(int i = 0; i < n; ++i)
        if(A[i].X > B[i].X) return puts("No"), 0;

    for(int i = 0; i < n - 1; ++i)
        if(A[i + 1].X <= B[i].X) return puts("Yes"), 0; // can sort every element of the remaining n - 2 elements with at most n - 2 swaps

    vector<int> perm(n);
    for(int i = 0; i < n; ++i)
        perm[B[i].Y] = A[i].Y; // what order should B be if sorted ascending-ly

    int idx = 0;
    int cycle_length = 0;

    do{
        idx = perm[idx]; // loop through permutation cycle
        cycle_length++;
    }while(idx != 0);

    //if cycle contains all n elements, it requires n - 1 swaps at minimum
    return puts(cycle_length == n ? "No": "Yes"), 0;
}