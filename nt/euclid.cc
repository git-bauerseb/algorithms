#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll euclid(ll a, ll b) {
    if (a == 0) return b;
    if (b == 0) return a;

    if (a < b) {swap(a,b);}

    ll r1 = a - (a / b) * b;
    if (r1 == 0) {return b;}

    ll r2 = b - (b / r1) * r1;
    while (r2 != 0) {
        ll rn = r1 - (r1 / r2) * r2;
        r1 = r2;
        r2 = rn; 
    }

    return r1;
}

ll extended_euclid(ll a, ll b, ll& s, ll& t) {
    bool flipped = a < b;
    if (a < b) swap(a,b);

    ll s0, s1, t0, t1;
    s0 = 1, s1 = 0;
    t0 = 0, t1 = 1;

    ll r0, r1;
    r0 = a, r1 = b;

    while (r1 != 0) {
        ll q = r0 / r1;
        ll rn = r0 - q * r1;
        ll sn = s0 - q * s1;
        ll tn = t0 - q * t1;
        r0 = r1, r1 = rn;
        s0 = s1, s1 = sn;
        t0 = t1, t1 = tn;
    }

    s = s0, t = t0;
    if (flipped) swap(s,t);

    return r0;
}

int32_t main() {

    assert (euclid(21,3) == 3);
    assert (euclid(21,5) == 1);


    long long x,y;
    long long b = 5033464705;
    long long c = 3137640337;
    extended_euclid(b,c,x,y);
    assert (x == 107535067 && y == -172509882);
    

    return 0;
}