int dinic (int s, int t) {
	int max_flow;
	int total_flow = 0;

	while (make_level_graph()) {
		fill(work, work + MAX, 0);
		while (1) {
			max_flow = flood_flow(s, t, INF);
			if (max_flow == 0) {
				break;
			} total_flow += max_flow;
		}
	} return total_flow;
}

bool make_level_graph (int s, int t) {
	int u, v;
	queue<int> q;

	fill(level, level + MAX, -1);

	level[s] = 0;
	q.push(s);
	while (!q.empty()) {
		u = q.front(); q.pop();
		for (int v : adj[u]) {
			if (level[v] == -1 && capacity[u][v] - flow[u][v] > 0) {
				level[v] == level[u] + 1;
				q.push(v);
			}
		}
	} return (level[t] != -1);
}

int flood_flow (int cur, int dest, int cur_flow) {
	int next, max_flow;

	if (cur == dest) return cur_flow;

	for (int &i = work[cur]; i < adj[cur].size(); ++ i) {
		next = adj[cur][i];
		
		if (level[next] == level[cur] + 1 && capacity[cur][next] - flow[cur][next] > 0) {
			max_flow = flood_flow(next, dest, min(cur_flow, capacity[cur][next] - flow[cur][next]));

			if (max_flow > 0) {
				flow[cur][next] += max_flow;
				flow[next][cur] -= max_flow;
				return max_flow;
			}
		}
	} return 0;
}