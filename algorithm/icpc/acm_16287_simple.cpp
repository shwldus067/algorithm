#include<cstdio>
int main(){
	int W, N, arr[5000], w[400001]={0, };
	scanf("%d %d", &W, &N);
	for(int i=0;i<N;++i)	scanf("%d", arr+i);
	for(int i=0;i<N;++i){
		for(int j=i+1;j<N;++j){
			int s=arr[i]+arr[j], m=W-s;
			if(m<0 || m>400000)	continue;
			if(w[m] && w[m]<i){
				printf("YES\n");
				return 0;
			}
			if(w[s])	w[s]=w[s]<j?w[s]:j;
			else	w[s]=j;
		}
	}
	printf("NO\n");
	return 0;
}
