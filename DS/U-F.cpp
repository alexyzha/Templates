#define tcT template<class T
tcT> using V = vector<T>;
using vi = V<int>;
#include <bits/stdc++.h>
using namespace std;

int MAXLEN = 200'005;

struct onion {
    vi h,p;
    onion(int n) : h(n,1), p(n) { iota(p.bg,p.ed,0); }

    int find(const int& x) {
        if(x==p[x]) return x;
        return p[x]=find(p[x]);
    }

    void join(const int&x, const int&y) {
        int px=find(x),py=find(y);
        if(px==py) return;
        if(h[px]>h[py]) p[py]=px;
        else if(h[px]<h[py]) p[px]=py;
        else p[py]=px,++h[px];
    }

    bool con(const int&x, const int&y) { return find(x)==find(y); }
};