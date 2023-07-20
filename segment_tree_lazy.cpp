#include <bits/stdc++.h>
 
using namespace std;
 
const int inf  = 1e9 + 7;
const int maxN = 2e5 + 7;
 
int n, q;
int a[maxN];
long long st[4 * maxN], lazy[4 * maxN];
 
void build(int id, int l, int r) {
    if (l == r) {
        st[id] = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    st[id] = st[2 * id] + st[2 * id + 1];
}

void fix(int id, int l, int r) {
    if (!lazy[id]) return;

    int mid = (l + r) >> 1;

    if (l != r){
        lazy[2 * id] += lazy[id];
        lazy[2 * id + 1] += lazy[id];
        st[2 * id] += lazy[id] * (mid - l + 1);
        st[2 * id + 1] += lazy[id] * (r - mid);
    }

    lazy[id] = 0;
}
 
void update(int id, int l, int r, int u, int v, int val) {
    if (l > v || r < u) return;
    if (u <= l && r <= v) {
        st[id] += (r - l + 1) * val;
        lazy[id] += val;
        return;
    }
    fix(id, l, r);
    int mid = l + r >> 1;
    update(2 * id, l, mid, u, v, val);
    update(2 * id + 1, mid + 1, r, u, v, val);
    st[id] = st[2 * id] + st[2 * id + 1];
}
 
long long get(int id, int l, int r, int u, int v) {
    if (l >  v || r <  u) return 0;
    if (l >= u && r <= v) return st[id];
    fix(id, l, r);
    int mid  = l + r >> 1;
    long long get1 = get(2 * id, l, mid, u, v);
    long long get2 = get(2 * id + 1, mid + 1, r, u, v);
    return get1 + get2;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    build(1, 1, n);
    cout << "\n";
    for (int i = 1; i <= 4 * n; i++)
        cout << st[i] << " ";
    cout << "\n";
    while (q--)
	{
		int type, l, r, val;
		cin >> type;
		if (type == 1)
		{
			cin >> l >> r >> val;
			update(1, 1, n, l, r, val);
	}
	else
		{
			cin >> l >> r;
			cout << get(1, 1, n, l, r) << "\n";
		}
	}
}

// Author: KodomoTachi
// Date: [20.07.2023]
// luv Kisa
