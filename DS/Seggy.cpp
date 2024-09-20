#include <bits/stdc++.h>
using namespace std;

#define tcT template<class T
tcT> using V = vector<T>;
using vi = V<int>;

struct SEG {
private:
    vi tree, lazy;
    int n;
public:   
    #ifdef MAX
    int merge(int x, int y) {
        
    }
    #endif

    #ifdef MIN
    #endif

    #ifdef SUM
    #endif

    void build(vi& nums, int i, int l, int r) {
        if(l==r) {
            tree[i] = nums[l];
            return;
        }
        int m = l+((r-l)>>1);
        build(nums,i*2+1,l,m);
        build(nums,i*2+2,m+1,r);
        tree[i] = merge(tree[i*2+1],tree[i*2+2]);
    }

    int query(int idx, int l, int r, int i, int j) {
        if(l>j||r<i) return 0;
        if(i<=l&&j>=r) return tree[idx];

        int m = l+((r-l)>>1);
        if(i>mid) return query(idx*2+2,m+1,r,i,j);
        else if(j<=mid) return query(idx*2+1,l,m,i,j);

        int lq = query(idx*2+1,l,m,i,j),
            rq = query(idx*2+2,m+1,r,i,j);

        return merge(lq,rq);
        //query(0,0,n-1,i.j), where i and j are the target range endpoints
    }

    void update(int idx, int l, int r, int num_idx, int val) {
        if(l==r) {
            tree[idx] = val;
            return;
        }

        int m = l+((r-l)>>1);
        if(num_idx > m) update(idx*2+2,m+1,r,num_index,val);
        else if(num_index <= m) update(idx*2+1,l,m,num_idx,val);

        tree[idx] = merge(tree[idx*2+1],tree[idx*2+2]);
        //update(0,0,n-1,i,val)
    }


};


/************************************************************************************************************************************************************************************/

#ifndef ALY
#define ALY
#pragma GCC optimize("03")
static int __star = []{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL),cout.tie(NULL);
    return 0;
}();
#define vcA template<class A
vcA> using V = vector<A>;
using vi = V<int>;
#endif

#define MAX

struct SEG {
private:
    int n, h;
    vi tree, lazy;
    #ifdef MAX
    int merge(int x, int y) { return max(x,y); }
    #endif
    #ifdef MIN
    int merge(int x, int y) { return min(x,y); }
    #endif
    void apply(int i, int val) {
        tree[i] = merge(tree[i],val);
        if(i < n) lazy[i] = merge(lazy[i],val);
    }

    void update_parent(int i) {
        while(i > 1) {
            i >>= 1;
            tree[i] = merge(tree[i*2],tree[i*2+1]);
            tree[i] = merge(tree[i],lazy[i]);
        }
    }

    void lazy_prop(int i) {
        for(int x = h; x > 0; --x) {
            int y = i >> x;
            if(lazy[y] > 0) {
                apply(y*2,lazy[y]);
                apply(y*2+1,lazy[y]);
                lazy[y] = 0;
            }
        }
    }
public:
    SEG(int n_) : n(n_), tree(2*n_,0), lazy(n_) {
        h = 1;
        while((1<<h)<n) ++h;
    }

    void update(int L, int R, int H) {
        L += n, R += n;
        int L0 = L, R0 = R;
        while(L <= R) {
            if(L&1) apply(L++,H);
            if(!(R&1)) apply(R--,H);
            L >>= 1, R >>= 1;
        }
        update_parent(L0), update_parent(R0);       //update up from child to parent to root
    }

    int query(int L, int R) {
        L += n, R += n;
        int ret = 0;
        lazy_prop(L), lazy_prop(R);                 //update from lazy before calculating
        while(L <= R) {
            if(L&1) ret = merge(ret,tree[L++]);
            if(!(R&1)) ret = merge(ret,tree[R--]);
            L >>= 1, R >>= 1;
        }
        return ret;
    }
};

/************************** NON LAZY **************************/


//MAX SEG, ITER

int LEN = 200005;

struct SEG {
private:
    int n, tree[MX];

    int op(int i, int j) {
        #ifdef SEG_MAX
        return max(i,j);
        #endif
        #ifdef SEG_MIN
        return min(i,j);
        #endif
    }
public:
    SEG(int n_) : n(n_) { memset(tree,0,sizeof(tree)); }

#ifdef SEG_MAKE
    void make(vi& arr, int n) {
        //assign
        F0R(i,n) tree[n+i] = arr[i];
        //assign parent based on children
        ROF(i,1,n) tree[i] = op(tree[2*i],tree[2*i+1]);
    }
#endif
    
    void update(int i, int val) {
        //at leaf node
        i += n, tree[i] = val;
        for(i >>= 1; i > 1; i >>= 1) tree[i] = op(tree[2*i],tree[2*i+1]);
        //move to parent, update parent
        //i > 1 doesn't affect root, can change to just i for root affect
    }
    
    int query(int left, int right, int mx = 0) {
        // change the index to leaf node first
        left += n, right += n;
        while(left <= right) {
            //compute if valid
            if(left&1) mx = op(mx,tree[left++]);
            if(!(right&1)) mx = op(mx,tree[right--]);
            //next level
            left >>= 1, right >>= 1;
        }
        return mx;
    }
};

//ADD

//len = 200005 or something

struct SEG {
private:
    int n, tree[LEN];
public:
    SEG(int n_) : n(n_) { memset(tree,0,sizeof(tree)); }

    void update(int i, int d) {
        i += n;
        tree[i] = d;
        while(i > 1) {
            i >>= 1;
            tree[i] = tree[2*i] + tree[2*i+1];
        }
    }

    int query(int left, int right) {
        left+=n,right+=n+1;
        int ret = 0;
        while(left < right) {
            if(left&1) ret += tree[left++];
            if(right&1) ret += tree[--right];
            left >>= 1, right >>= 1;
        }
        return ret;
    }
};