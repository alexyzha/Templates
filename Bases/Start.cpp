//reqs
//#include <bits/stdc++.h>
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
#include <climits>
using namespace std;

//def
#ifndef ALY
#define ALY
//init
    #pragma GCC optimize("03")
    static int __star = []{
        ios_base::sync_with_stdio(0);
        cin.tie(NULL),cout.tie(NULL);
        return 0;
    }();
//typedef
    using ll = long long;
    using ull = unsigned long long;
    using u8 = uint8_t;
    using u16 = uint16_t;
    using u32 = uint32_t;
    using u64 = uint64_t;
    using in8 = uint8_t;
    using in16 = uint16_t;
    using in32 = uint32_t;
    using in64 = uint64_t;
    using db = long double;
    using str = string;
//pairs
    using pi = pair<int,int>;
    using pl = pair<ll,ll>;
    #define mp make_pair
    #define f first
    #define s second
//vecs
    #define vcA template<class A
    vcA> using V = vector<A>;
    vcA> using MAT = V<V<A>>;
    using vi = V<int>;
    using vb = V<bool>;
    using vl = V<ll>;
    using vd = V<db>;
    using vs = V<str>;
    using vpi = V<pi>;
    using vpl = V<pl>;
    using mat = V<vi>;
//vec ops
    #define sz(x) int((x).size())
    #define bg(x) begin(x)
    #define ed(x) end(x)
    #define all(x) begin(x),end(x)
    #define rall(x) x.rbegin(),x.rend()
    #define srt(x) sort(all(x))
    #define rsz resize
    #define ins insert
    #define pb push_back
    #define eb emplace_back
    #define em empty()
    #define ft front()
    #define bk back()
    #define ppb pop_back()
    #define ppf pop_front()
    #define pp pop()
    #define tp top()
    #define lb lower_bound
    #define ub upper_bound
    vcA> int lwb(V<A>&a,const A&b) { return int(lb(all(a),b)-bg(a)); }
    vcA> int upb(V<A>&a,const A&b) { return int(lb(all(a),b)-bg(a)); }
//loops
    #define FOR(i,a,b) for(int i=(a);i<(b);++i)
    #define F0R(i,a) FOR(i,0,a)
    #define ROF(i,a,b) for(int i=(b)-1;i>=(a);--i)
    #define R0F(i,a) ROF(i,0,a)
    #define xtime(a) F0R(_,a)
    #define each(a,x) for(auto&a:x)
//numbers
    static constexpr int MOD = 1'000'000'007;
    static constexpr int ALTMOD = 998'244'353;
    static constexpr int MX = 200'005;
    static constexpr ll LMX = 1e18;
    static constexpr int XDIR[4]{1,0,-1,0}, YDIR[4]{0,1,0,-1};
//pq
    template<class P> using pqg = priority_queue<P,vector<P>,greater<P>>; //pop lesser
    template<class P> using pql = priority_queue<P,vector<P>,less<P>>; //pop greater
//bitmax & mog
    constexpr int pct(int x) { return __builtin_popcount(x); }
    constexpr int ctz(int x) { return __builtin_ctz(x); } //count trailing zero
    constexpr int clz(int x) { return __builtin_clz(x); } //count leading zero
//math
    // a / b
    ll floored(ll a,ll b) { return a/b-((a^b)>0&&a%b); }
    ll ceiled(ll a,ll b) { return a/b+((a^b)>0&&a%b); }
//minmax
    vcA> bool fx_min(A&a,const A&b) { return b < a ? a = b, 1 : 0; }
    vcA> bool fx_max(A&a,const A&b) { return a < b ? a = b, 1 : 0; }
//prints
    vcA> void printvec(V<A>&a) { each(v,a) { cout << v << ' '; } cout << endl; }
    template<typename C>
    void meow(C num) {
        for(int bits=sizeof(num)*8;bits--;num>>=1) cout << !!(num&1);
        cout << endl;
    }
#endif