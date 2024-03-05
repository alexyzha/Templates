#include <bits/stdc++.h>
using namespace std;
//nums
using ll = long long;
using ull = unsigned long long;
using db = long double;
using str = string;
//pairs
using pi = pair<int,int>;
#define mp make_pair
#define f first
#define s second
//vecs
#define tcT template<class T
tcT> using V = vector<T>; 
tcT, size_t SZ> using AR = array<T,SZ>;
using vi = V<int>;
using vb = V<bool>;
using vpi = V<pi>;
//operations
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rsz resize
#define pb push_back
#define ft front()
#define bk back()
//loops
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for(int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(a,x) for(auto& a: x)
//const nums
const int MOD = 1e9+7;
const db PI = acos((db)-1);
mt19937 rng(0);
//min/max + set
tcT> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; } // set a = min(a,b)
tcT> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } // set a = max(a,b)