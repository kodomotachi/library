#include <bits/stdc++.h>
using namespace std;

// Kosaraju algorithm
// Count number of strongly connected components

vector<vector<int>> graph(2002);
vector<vector<int>> graph_reverse(2002);
int n;
stack<int> pq;
bool visited[2002];

void dfs_push(int u) // use DFS to push edge can't visited other edge and push it into stack
{
	visited[u] = true;
	for (int x : graph[u])
		if (!visited[x])
			dfs_push(x);
	pq.push(u);
}

void dfs(int u) // use DFS normal
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
		graph_reverse[y].push_back(x); // push reverse verticle 
	}
	for (int i = 1; i <= n; i++)
		if (!visited[i])
			dfs_push(i); 
	int cnt = 0; // create variable to count strongly connected components
	memset(visited, false, sizeof(visited)); // reset visited array
	while (!pq.empty())
	{
		int x = pq.top(); // use element on top stack
		pq.pop();
		if (!visited[x])
		{
			dfs(x);
			++cnt; // increase strongly connected components by 1
		}
	}
	return cout << cnt, 0; // print answer
}
