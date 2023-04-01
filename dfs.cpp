#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 7;

vector<vector<int>> graph(MAXN);
bool visited[MAXN];
int n;

void DFS (int u)
{
	visited[u] = true
	for (int x :  a[u])
		if (!visited[x])
			DFS(x);
}

int main()
{
	cin.tie(0) -> sync_with_stdio(0);
	int m;
	cin >> n >> m; // input n and m
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(y);
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (!visited[i])
		{
			++cnt; // count component
			DFS(i);
		}
	return cout << (cnt == 1 ? "YES" : "NO"), 0; // if graph has only 1 component, print "YES", otherwise, print "NO".
}
