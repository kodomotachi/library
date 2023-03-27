#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAXN = 2e5 + 4;

ll t[4 * MAXN] = {-INT_MAX};
ll lazy[4 * MAXN], a[MAXN];

void build(int id, int l, int r)
{
	if (l == r)
		return t[id] = a[l], void();
	int mid = (l + r) / 2;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid + 1, r);
	t[id] = max(t[id * 2], t[id * 2 + 1]);
}

void update_range(int id, int l, int r, int u, int v, int k)
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

ll get(int id, int l, int r, int u, int v)
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
	for (int i = 1; i <= 4 * n; i++)
		cout << t[i] << " \n"[i == 4 * n];
	while (q--)
	{
		int query;
		cin >> query;
		if (query == 1)
		{
			int left, right, value;
			cin >> left >> right >> value;
			update_range(1, 1, n, left, right, value);
			for (int i = 1; i <= 4 * n; i++)
				cout << t[i] << " \n"[i == 4 * n];
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
