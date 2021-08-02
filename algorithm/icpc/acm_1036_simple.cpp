#include<cstdio>
#include<cstring>
inline int chtoint(char c){return c<='9'?c-48:c-55;}
inline int inttoch(int n){return n<=9?n+48:n+55;}
inline double pow(int n, int r){
	double res=1;
	while(r--)	res*=n;
	return res;
}
int main(){
	int N, K, cnt[55][36]={0, };
	scanf("%d", &N);
	char str[51];
	while(N--){	// 각 문자마다 자리값 갯수
		scanf(" %s", str);
		int t=0;
		for(int i=strlen(str)-1;i>=0;--i){
			cnt[t++][chtoint(str[i])]++;
		}
	}
	scanf("%d", &K);
	int alp[36]={0, };
	while(K--){	// K^2동안 문자마다 증가량 큰 것 
		int idx=-1;
		double val, max=0;
		for(int i=0;i<35;++i){
			if(alp[i])	continue;
			val=0;
			for(int j=0;j<54;++j){
				if(cnt[j][i])	val+=cnt[j][i]*(35-i)*pow(36, j);
			}
			if(max<val){
				idx=i;max=val;
			}
		}
		if(idx>=0){
			alp[idx]=1;
			for(int i=0;i<55;++i){
				cnt[i][35]+=cnt[i][idx];
				cnt[i][idx]=0;
			}
		}
		else break;
	}
	int sum;
	char ans[55]={0, };
	for(int i=0;i<55;++i){
		sum=0;
		for(int j=0;j<36;++j)	sum+=j*cnt[i][j];
		ans[i+1]=(ans[i]+sum)/36;
		ans[i]=inttoch((ans[i]+sum)%36);
	}
	int f=0;
	for(int i=54;i>=0;--i){
		if(ans[i]>'0' || i==0)	f=1;
		if(f)	printf("%c", ans[i]);
	}
	printf("\n");
	return 0;
}
