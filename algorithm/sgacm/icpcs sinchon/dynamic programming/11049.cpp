#include <stdio.h>
#define MAX 550
#define INF 1234567890

int row[MAX];
int col[MAX];
int dp[MAX][MAX];

int main(){
	int N, minValue, calcResult;
	scanf("%d", &N);

	for(int i = 0, r, c; i < N; i++){
		scanf("%d%d", &r, &c);
		row[i] = r;
		col[i] = c;
	}

	for(int len = 1; len < N; len++){
		for(int i = 0; i < N; i++){
			int j = i + len;
			if(!(j < N)) break;

			minValue = INF;
			for(int k = i; k < j; k++){
				calcResult = dp[i][k] + dp[k+1][j] + row[i]*col[k]*col[j];
				if(minValue > calcResult) minValue = calcResult;
			}
			dp[i][j] = minValue;
		}
	}

	printf("%d\n", dp[0][N-1]);
}