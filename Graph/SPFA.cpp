
void SPFA (int n, int s) {
	queue<int> q;
	vector<bool> isInQ(n + 1, false);

	for (int i = 1; i <= n; ++ i) {
		d[i] = INF;
	} d[s] = 0;

	q.push(s); isInQ[s] = true;
	while (!q.empty()) {
		int u = q.front(); q.pop(); isInQ[u] = false;
		for (auto p : adj[u]) {
			int v = p.first, w = p.second;
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				if (!isInQ[v]) {
					q.push(v);
					isInQ[v] = true;
				}
			}
		}
	}
}