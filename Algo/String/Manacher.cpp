#include <bits/stdc++.h>
#define tcT template<class T
tcT> using V = vector<T>; 
tcT, size_t SZ> using AR = array<T,SZ>;
using vi = V<int>;

// longest palindrome in a string in O(n), parity doesn't matter:

vi manacher(string s) {
    string t;
    for(auto c : s) t += string("#") + c;
    auto res = MOH(t + "#");
    return vi(begin(res) + 1, end(res) - 1);
}

vi MOH(string s) {
    int n = s.size();
    s = "$" + s + "^";
    vi p(n + 2);
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]]) p[i]++;
        if(i + p[i] > r) l = i - p[i], r = i + p[i];
    }
    return vi(begin(p) + 1, end(p) - 1);
}