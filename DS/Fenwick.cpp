#include <bits/stdc++.h>
using namespace std;

// fenwick tree

struct BIT {
private:
    vector<int> b;
    int n;
public:
    BIT(const int& i) b(i+1), n(i) {}

    void update(int i, const int& d) { //delta
        ++i;
        while(i<=n) b[i]+=d,i+=i&-i;
    }

    int query(int i) {
        ++i;
        int r=0;
        while(i>0) r+=b[i],i-=i&-i;
        return r;
    }

    int range(int x, int y) { return query(y)-query(x-1); }
};


// template ver:

#define vcA template<class A
vcA> using V = vector<A>;
vcA> using MAT = V<V<A>>;
using vi = V<int>;

template <typename B>
struct BIT {
    V<B> tree;
    int n;
    BIT(int n_) : n(n_), tree(n_+1,0) {}

    void update(int i, B d) { for(i=i+1;i<=n;i+=i&-i) tree[i]+=d; }

    B query(int i) {
        B sum = 0;
        for(i=i+1;i>0;i-=i&-i) sum+=tree[i];
        return sum;
    }

    B range(int l, int r) { return query(r)-query(l-1); }
};