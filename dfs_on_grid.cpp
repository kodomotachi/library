#include <bits/stdc++.h>
using namespace std;

bool visited[1002][1002]; // all element of visited is false
char a[1002][1002]; // data structure where contain graph [present by matrix]

int n, m;
int dx[] = {1, 0, 0, -1};
int dy[] = {0, 1, -1, 0};

void dfs(int u, int v)
{
	visited[u][v] = true;
	for (int i = 0; i < 4; i++)
		if (u + dx[i] > 0 && u + dx[i] <= n && v + dy[i] > 0 && v + dy[i] <= m && !visited[u + dx[i]][v + dy[i]] && a[u + dx[i]][v + dy[i]] == '.')
			dfs(u + dx[i], v + dy[i]);
}

int main()
{
	cin.tie(0) -> sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
	/* example, input
	...*
	..*.
	..*.
	..*.

	Requirement: Count the number of component of matrix. Answer in this example is 2 (we just count component of the symbol (.)). 
	*/
	int cnt = 0; // variable that count component
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			if (!visited[i][j])
			{
				dfs(i, j);
				cnt++;
			}
		}
	return cout << cnt, 0;
}