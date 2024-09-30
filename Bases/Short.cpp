#pragma GCC optimize("03")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
//singles
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
#define TC template<class T
TC> using V = vector<T>; 
TC, size_t SZ> using AR = array<T,SZ>;
using vi = V<int>;
using vb = V<bool>;
using vpi = V<pi>;
//str and fxn
template <typename A>
#pragma once

// To use most bits rather than just the lowest ones:
struct chash { // large odd number for C
	const uint64_t C = ll(4e18 * acos(0)) | 71;
	ll operator()(ll x) const { return __builtin_bswap64(x*C); }
};
__gnu_pbds::gp_hash_table<ll,int,chash> h({},{},{},{},{1<<16});
// https://github.com/kth-competitive-programming/kactl/blob/main/content/data-structures/HashMap.h
using oset = tree<A,null_type,less<A>,rb_tree_tag,tree_order_statistics_node_update>;
using deez = function<void()>;
//operations
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rsz resize
#define pb push_back
#define pbk pop_back()
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
TC> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; } // set a = min(a,b)
TC> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } // set a = max(a,b)
//init
static int __star = []{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL),cout.tie(NULL);
    return 0;
}();