#include <bits/stdc++.h>
using namespace std;

#define ll long long

// Đề bài yêu cầu:
// Cho mảng gồm n phần tử và q tru vấn, mỗi truy vấn gồm 2 số nguyên l, r
// Yêu cầu: đi tìm giá trị nhỏ nhất trong đoạn [l, r]

// Ý tưởng bài toán đon giản, chia mảng thành các khoảng sqrt(n) phần tử và lưu giá trị nhỏ
// nhất bên trong mỗi sqrt(n) phần tử đó

int main()
{
	cin.tie(0) -> sync_with_stdio(0);
	int n;
	cin >> n;
	int a[n];
	for (int &x : a)
		cin >> x;
	int len = (int)sqrt(n) + 1; // size of the block and the number of blocks
	vector<int> b(len, INT_MAX);
	for (int i = 0; i < n; i++)
		b[i / len] = min(b[i / len], a[i]);
	int q;
	cin >> q;
	while (q--)
	{
		int l, r;
		cin >> l >> r;
		vector<int> ans;
		for (int i = l; i <= r;)
			if (i % len == 0 && i + len - 1 <= r) // if the whole block starting at i belong [l, r]
				ans.push_back(b[i / len]), i += len;
			else
				ans.push_back(a[i]), ++i;
		sort(ans.begin(), ans.end());
		cout << ans[0] << "\n";
	}
	return cout << len, 0;
}