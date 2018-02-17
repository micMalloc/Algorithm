/* S : Source, T : Sink, N : The number of Vertices of the Graph */
/* Use Edmond-Karp */
int network_flow (int n, int s, int t) {
	int total_flow = 0;

	memset(flow, 0, sizeof(flow));
	
	while (true) {
		vector<int> parent(MAX, -1);
		queue<int> q;

		parent[s] = s;
		q.push(s);
		/* Find Augmenting Path using BFS */
		while (!q.empty() && parent[t] == -1) {
			int u = q.front(); q.pop();
			for (int v = 1; v <= n; ++ v) {
				if (capacity[u][v] - flow[u][v] > 0 && parent[v] == -1) {
					q.push(v);
					parent[v] = u;
				}
			}
		}
		/* There is no path */
		if (parent[t] == - 1) {
			break;
		}

		int max_flow = INF;
		for (int v = 1; v != s; v = parent[v]) {
			int r = capacity[parent[v]][v] - flow[parent[v]][v];
			max_flow = min(max_flow, r);
		}

		for (int v = 1; v != s; v = parent[v]) {
			flow[parent[v]][v] += max_flow;
			flow[v][parent[v]] -= max_flow;
		}
		total_flow += max_flow;
	} return total_flow;
}