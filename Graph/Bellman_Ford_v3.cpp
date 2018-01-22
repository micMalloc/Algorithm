bool Bellman_Ford (int source, int n) {
	int u, v, w;
	
	initSingleSource(source, n);
	for (int i = 0; i < n - 1; ++ i) {
		for (int j = 1; j <= n; ++ j) {
			for (auto p : adj[j]) {
				relaxation(j, p.first, p.second);
			}
		}
	}

	for (int i = 1; i <= n; ++ i) {
		for (auto p : adj[i]) {
			if (relaxation(i, p.first, p.second)) {
				return false;
			}
		}
	} return true;
}

void initSingleSource (int source, int n) {
	for (int i = 1; i <= n; ++ i) {
		if (i == source) {
			d[i] = 0;
		} else {
			d[i] = INF;
		}
	}
}

bool relaxation (int u, int v, int w) {
	bool isRelax = false;
	
	if (d[v] > d[u] + w) {
		d[v] = d[u] + w;
		isRelax = true;
	} return isRelax;
}