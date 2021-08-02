#include <stdio.h>
#include <algorithm>
#include <vector>
#define MAXN 1050

using namespace std;

struct edge {
	int from, to, capacity, flow;
	edge *reverse_edge;

	edge(int u, int v, int c) : from(u), to(v), capacity(c), flow(0) {}

	int residual() {
		return capacity - flow;
	}

	void add_flow(int new_flow) {
		flow += new_flow;
		reverse_edge->flow -= new_flow;
	}
};

struct flow {
	int V, E; // # nodes, # edges
	int source, sink;
	vector<edge*> adj[MAXN];

	int total_flow = 0;

	void add_edge(int u, int v, int c, bool directed = true) {
		edge *e1 = new edge(u, v, c);
		edge *e2 = new edge(v, u, (directed) ? 0 : c); // make back edge
		e1->reverse_edge = e2;
		e2->reverse_edge = e1;
		adj[u].push_back(e1);
		adj[v].push_back(e2);
	}

	bool find_augmenting_path(int *trace, edge **back_edge) {
		for (int i = 0; i < MAXN; i++) {
			trace[i] = -1;
			back_edge[i] = NULL;
		}
		int queue[MAXN] = { 0, };
		int fr = 0, rr = -1;
		queue[++rr] = source;
		while (rr >= fr && trace[sink] == -1) { // BFS until visit sink
			int cur = queue[fr++];
			for (auto e : adj[cur]) {
				int nxt = e->to;
				if (trace[nxt] == -1 && e->residual() > 0) { // move toward residual edge
					trace[nxt] = cur; // trace reverse route
					back_edge[nxt] = e;
					queue[++rr] = nxt;
				}
			}
		}
		if (trace[sink] == -1) return false;
		return true;
	}

	int find_max_flow() {
		int trace[MAXN];
		edge* back_edge[MAXN] = { 0, };
		while (find_augmenting_path(trace, back_edge)) {
			int new_flow = 1234567890;
			for (int i = sink; i != source; i = trace[i]) {
				new_flow = min(new_flow, back_edge[i]->residual());
			}
			for (int i = sink; i != source; i = trace[i]) {
				back_edge[i]->add_flow(new_flow);
			}
			total_flow += new_flow;
		}
		return total_flow;
	}

}G;

void input() {
	int N, M;
	scanf("%d%d", &N, &M);
	for(int i = 1, t; i <= N; i++){
		scanf("%d", &t);
		for(int j = 0, tt; j < t; j++){
			scanf("%d", &tt);
			tt += N;
			G.add_edge(i, tt, 1);
		}
	}
	int S = G.source = 0;
	int T = G.sink = N + M + 1;
	for(int i = 1; i <= N; i++){
		G.add_edge(S, i, 1);
	}
	for(int i = N+1; i <= N+M; i++){
		G.add_edge(i, T, 1);
	}
}

int main() {
	input();
	G.find_max_flow();
	printf("%d\n", G.total_flow);
}