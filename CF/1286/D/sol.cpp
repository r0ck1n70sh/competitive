#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mod= 998244353;
const int maxn= 100005;

struct fraction{
	ll p, q;
	fraction(ll p, ll q): p(p), q(q){}
};

struct event{
	int idx;
	fraction t;
	event(fraction t, int idx): t(t), idx(idx){}
};

bool operator < (fraction a, fraction b){
	return a.p*b.q < a.q*b.p;
}
bool operator < (event a, event b){
	return a.t<b.t;
}

int n, pos[maxn], v[maxn], p[maxn];
