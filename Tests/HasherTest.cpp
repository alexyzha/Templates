//reqs
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
    using vi = V<int>;
    using vb = V<bool>;
    using vl = V<ll>;
    using vd = V<db>;
    using vs = V<str>;
    using vpi = V<pi>;
    using vpl = V<pl>;
//vec ops
    #define sz(x) int((x).size())
    #define bg(x) begin(x)
    #define all(x) begin(x),end(x)
    #define rall(x) x.rbegin(),x.rend()
    #define srt(x) sort(all(x))
    #define rsz resize
    #define ins insert
    #define pb push_back
    #define eb emplace_back
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
    #define R0F(i,a) R0F(i,0,a)
    #define xtime(a) F0R(_,a)
    #define each(a,x) for(auto&a:x)
//numbers
    static constexpr int MOD = 1'000'000'007;
    static constexpr int ALTMOD = 998'244'353;
    static constexpr int MX = 200'005;
    static constexpr ll LMX = 1e18;
    static constexpr int XDIR[4]{1,0,-1,0}, YDIR[4]{0,1,0,-1};
//pq
    template<class P> using pqg = priority_queue<P,vector<P>,greater<P>>;
    template<class P> using pql = priority_queue<P,vector<P>,less<P>>;
//bitmax & mog
    constexpr int pct(int x) { return __builtin_popcount(x); }
//math
    // a / b
    ll floored(ll a,ll b) { return a/b-((a^b)>0&&a%b); }
    ll ceiled(ll a,ll b) { return a/b+((a^b)>0&&a%b); }
//minmax
    vcA> bool fx_min(A&a,const A&b) { return b < a ? a = b, 1 : 0; }
    vcA> bool fx_max(A&a,const A&b) { return a < b ? a = b, 1 : 0; }
//prints
    vcA> void printvec(V<A>&a) { each(v,a) { cout << v << ' '; } cout << endl; }
#endif


/************************************************************************************************************/

template<typename T>
struct HASHER {
private:
    static constexpr int MAXLEN = 100'005;
    u64 BASE_POW[MAXLEN];
    u64 H_MOD;
    u64 H_SEED;
    u64 H_BASE;
    V<u64> pre;
    #ifdef HASHER_SUF
        V<u64> suf;
    #endif
    int64_t modmulti(u64 a, u64 b){
        u64 l1 = (u32)a, h1 = a >> 32, l2 = (u32)b, h2 = b >> 32;
        u64 l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
        u64 ret = (l & H_MOD) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
        ret = (ret & H_MOD) + (ret >> 61);
        ret = (ret & H_MOD) + (ret >> 61);
        return ret - 1;
    }

    void init() {
        BASE_POW[0] = 1;
        FOR(i,1,MAXLEN+1) BASE_POW[i] = modmulti(BASE_POW[i-1],H_BASE);
    }
public:
    HASHER(V<T>& arr) : H_MOD((1ULL<<61)-1) {
        if(!BASE_POW[0]) init();
        H_SEED = chrono::system_clock::now().time_since_epoch().count();
        H_BASE = mt19937_64(H_SEED)() % (H_MOD/3) + (H_MOD/3);
        int len = sz(arr);
        assert(len < MAXLEN);
        pre.rsz(len+3,0);
        FOR(i,1,len+1) {
            pre[i] = modmulti(pre[i-1],H_BASE) + arr[i-1] + 997;
            if(pre[i] >= H_MOD) pre[i] -= H_MOD;
        }
        #ifdef HASHER_SUF
            suf.rsz(len+3,0);
            ROF(i,1,len+1) {
                pre[i] = modmulti(pre[i+1],H_BASE) + arr[i+1] + 997;
                if(suf[i] >= H_MOD) pre[i] -= H_MOD;
            }
        #endif
    }

    u64 pre_hash(int l, int r) {
        u64 h = pre[r+1] - modmulti(BASE_POW[r-l+1],pre[l]);
        return h < 0 ? h + H_MOD : h;
    }
    #ifdef HASHER_SUF
        u64 suf_hash(int l, int r) {
            u64 h = suf[l+1] - modmulti(BASE_POW[r-l+1],suf[r+2]);
            return h < 0 ? h + H_MOD : h;
        }
    #endif
};

/************************************************************************************************************/

int main() {
    V<char> test = {'a','b','c','d','e','a','b','c','d','e'};
    auto START = chrono::high_resolution_clock::now();
    HASHER<char> hsh(test);

    //cout << hsh.pre_hash(0,4) << ' ' << hsh.pre_hash(5,9);

    auto STOP = chrono::high_resolution_clock::now();
    
    auto LEN = chrono::duration_cast<chrono::milliseconds>(STOP-START);
    cout << LEN.count() << " millisex\n";
    return 0;
}