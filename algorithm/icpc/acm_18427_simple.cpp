#include<cstdio>
using namespace std;
#define mod 10007
int main(){
	int N, M, H, arr[2][1001]={0, }, t, tt=0, nt=1;
	char c;
	scanf("%d %d %d", &N, &M, &H);
	arr[tt][0]=arr[nt][0]=1;
	while(N--){
		for(int i=0;i<=H;++i)	arr[tt][i]=arr[nt][i];
		do{
			scanf("%d%c", &t, &c);
			for(int i=0;i+t<=H;++i)
				arr[tt][i+t]=(arr[tt][i+t]+arr[nt][i])%mod;
		}while(c!='\n');
		nt=tt;tt^=1;
	}
	printf("%d\n", arr[nt][H]);
	return 0;
}
