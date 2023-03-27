#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAXN = 2e5 + 4;

ll t[4 * MAXN] = {-INT_MAX};
ll lazy[4 * MAXN], a[MAXN];

void build(int id, int l, int r) // build array to create segment tree
{
	if (l == r)
		return t[id] = a[l], void();
	int mid = (l + r) / 2;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid + 1, r);
	t[id] = max(t[id * 2], t[id * 2 + 1]);
}

void update_range(int id, int l, int r, int u, int v, int k) // update range [l, r] add value from input
{
	if (v < l || r < u)
		return;
	if (u <= l && r <= v)
	{
		t[id] += k;
		lazy[id] += k;
		return;
	}
	int mid = (l + r) / 2;
	update_range(id * 2, l, mid, u, v, k);
	update_range(id * 2 + 1, mid + 1, r, u, v, k);
	t[id] = max(t[id * 2], t[id * 2 + 1]) + lazy[id];
}

ll get(int id, int l, int r, int u, int v) // get maximum in element position [l, r]
{
	if (v < l || r < u)
		return 0;
	if (u <= l && r <= v)
		return t[id];
	int mid = (l + r) / 2;
	int t1 = get(id * 2, l, mid, u, v);
	int t2 = get(id * 2 + 1, mid + 1, r, u, v);
	return max(t1, t2) + lazy[id];
}

int main()
{
	cin.tie(0) -> sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	build(1, 1, n);
	int q;
	cin >> q;
	while (q--)
	{
		int query;
		cin >> query;
		if (query == 1)
		{
			int left, right, value;
			cin >> left >> right >> value;
			update_range(1, 1, n, left, right, value);
		}
		else
		{
			int left, right;
			cin >> left >> right;
			cout << get(1, 1, n, left, right) << "\n";
		}
	}
	return 0;
}

// Youtube link: https://www.youtube.com/watch?v=5damMQqligI&t=1447s
// Algorithm link: https://cp-algorithms.com/data_structures/segment_tree.html#range-updates-lazy-propagation
// author: KodomoTachi [28.03.2023]
// luv Kisa
