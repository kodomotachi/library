#include <bits/stdc++.h>
using namespace std;

// Kosaraju algorithm
// Count number of strongly connected components

vector<vector<int>> graph(2002);
vector<vector<int>> graph_reverse(2002);
int n;
stack<int> pq;
bool visited[2002];

void dfs_push(int u)
{
	visited[u] = true;
	for (int x : graph[u])
		if (!visited[x])
			dfs_push(x);
	pq.push(u);
}

void dfs(int u)
{
	visited[u] = true;
	for (int x : graph_reverse[u])
		if (!visited[x])
			dfs(x);
}

int main()
{
	cin.tie(0) -> sync_with_stdio(0);
	int m;
	cin >> n >> m;
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph_reverse[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
		if (!visited[i])
			dfs_push(i);
	int cnt = 0;
	memset(visited, false, sizeof(visited));
	while (!pq.empty())
	{
		int x = pq.top();
		pq.pop();
		if (!visited[x])
		{
			dfs(x);
			++cnt;
		}
	}
	return cout << cnt, 0;
}