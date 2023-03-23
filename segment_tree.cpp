#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAXN = 2e5 + 4;

ll a[MAXN];
ll t[4 * MAXN];

void build(int id, int l, int r) // build array to create segment tree
{
	if (l == r)
		return t[id] = a[l], void();
	int mid = (l + r) / 2;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid + 1, r);
	t[id] = min(t[id * 2], t[id * 2 + 1]);
}

ll get(int id, int l, int r, int u, int v) // get min with comfortable range [u, v]
{
	if (r < u || l > v)
		return INT_MAX;
	if (u <= l && r <= v)
		return t[id];
	int mid = (l + r) / 2;
	ll t1 = get(id * 2, l, mid, u, v);
	ll t2 = get(id * 2 + 1, mid + 1, r, u, v);
	return min(t1, t2);
}

void update(int id, int l, int r, int p, int val) // update value in detail position and update again in Segment tree
{
	if (p < l || p > r)
		return;
	if (l == r)
		return t[id] = val, void();
	int mid = (l + r) / 2;
	update(id * 2, l, mid, p, val);
	update(id * 2 + 1, mid + 1, r, p, val);
	t[id] = min(t[id * 2], t[id * 2 + 1]);
}

int main()
{
	cin.tie(0) -> sync_with_stdio(0);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	build(1, 1, n);
	while (q--)
	{
		int query;
		cin >> query;
		if (query == 1) // update a[pos] = value;
		{
			int pos, value;
			cin >> pos >> value;
			update(1, 1, n, pos, value);
		}
		else if (query == 2) // get min with position [l, r]
		{
			int left, right;
			cin >> left >> right;
			cout << get(1, 1, n, left, right) << "\n";
		}
	}
	return 0;
}

// Youtube: https://www.youtube.com/watch?v=9U1pChOERjg&t=4046s
// Blog's link: https://vnoi.info/wiki/algo/data-structures/segment-tree-extend
// author: KodomoTachi [23.03.2023]
// luv Kisa
