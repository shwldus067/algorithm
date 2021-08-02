#include <stdio.h>
#include <algorithm>
#include <vector>
#define MAX 10050


int 				N, root;
int					w[MAX];
int					dp[MAX][2];
std::vector<int>	adj[MAX];
std::vector<int>	answer;

void dfsFillTable(int parentNode, int currentNode){
	int resultCurrentIncluded = 0;
	int resultCurrentNotIncluded = 0;

	for(int nextNode : adj[currentNode]){
		if(nextNode == parentNode) continue;
		dfsFillTable(currentNode, nextNode);

		resultCurrentIncluded += dp[nextNode][0];
		resultCurrentNotIncluded += std::max(dp[nextNode][0], dp[nextNode][1]);
	}

	dp[currentNode][0] = resultCurrentNotIncluded;
	dp[currentNode][1] = resultCurrentIncluded + w[currentNode];

	return;
}

void dfsTraceAnswer(int parentNode, int currentNode, int mayInclude){
	bool include = false;
	if(mayInclude && dp[currentNode][1] > dp[currentNode][0]) include = true;

	if(include) answer.push_back(currentNode);

	for(auto nextNode : adj[currentNode]){
		if(nextNode == parentNode) continue;
		dfsTraceAnswer(currentNode, nextNode, !include);
	}

	return;
}

int main(){
	scanf("%d", &N);

	for(int i = 0; i < N; i++){
		scanf("%d", &w[i]);
	}
	for(int i = 0, u, v; i < N-1; i++){
		scanf("%d%d", &u, &v);
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	root = 0;

	dfsFillTable(-1, root);
	dfsTraceAnswer(-1, root, true);

	printf("%d\n", std::max(dp[root][0], dp[root][1]));
	std::sort(answer.begin(), answer.end());
	for(auto element : answer) printf("%d ", element+1);
	printf("\n");
}