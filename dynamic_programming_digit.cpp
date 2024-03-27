#include <bits/stdc++.h>
using namespace std;

#define ll long long

int d, k;
ll dp[20][3][3][140];


// note that 'leading_zero' with 0 for number is not number and 1 for otherwise.
// 'smaller' for variable that if your current digit is reach to limit, which you can't create number greater than input 
ll calc(string s, int idx, int smaller, int leading_zero, int cnt)
{
	if (idx == s.size())
	{
		if (cnt == k)
			return 1;
		return 0;
	}

	if (dp[idx][smaller][leading_zero][cnt] != -1)
		return dp[idx][smaller][leading_zero][cnt];

	ll ans = 0;
	int limit = (smaller == 1 ? 9 : s[idx] - '0');

	for (int i = 0; i <= limit; i++)
	{
		int tmp = cnt;

		if (i == d)
			if ((i == 0 && leading_zero == 1) || (i > 0))
				++tmp;

		ans += calc(s, idx + 1, (smaller || (i < s[idx] - '0')), (leading_zero || i > 0), tmp);
	}

	dp[idx][smaller][leading_zero][cnt] = ans;
	return ans;
}

ll solve(string s)
{
	memset(dp, -1, sizeof(dp));
	return calc(s, 0, 0, 0, 0);
}

int main()
{
	cin.tie(0) -> sync_with_stdio(0);

	ll a, b;
	cin >> a >> b >> d >> k;

	cout << solve(to_string(b)) - solve(to_string(a - 1));

	return 0;
}

// [27.03.2024]
// luv Kisa
